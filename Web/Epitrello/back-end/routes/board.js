const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

router.get('/boards', (req, res) => {
    const userId = req.query.user_id;

    // Check if user_id is provided
    if (!userId) {
        return res.status(400).json({ error: 'user_id is required' });
    }

    const query = `
        SELECT b.board_id, b.name, l.list_id, l.name AS list_name, 
               t.task_id, t.title, t.description, t.due_date, t.completed 
        FROM Boards b
        LEFT JOIN Lists l ON b.board_id = l.board_id
        LEFT JOIN Tasks t ON l.list_id = t.list_id
        WHERE b.user_id = ?
    `;

    db.all(query, [userId], (err, rows) => {
        if (err) {
            return res.status(500).json({ error: 'Database error' });
        }
        
        const boardsMap = {};

        rows.forEach(row => {
            if (!boardsMap[row.board_id]) {
                boardsMap[row.board_id] = {
                    board_id: row.board_id,
                    name: row.name,
                    lists: []
                };
            }

            if (row.list_id) {
                // Find the existing list or create a new one
                let list = boardsMap[row.board_id].lists.find(list => list.list_id === row.list_id);

                if (!list) {
                    list = {
                        list_id: row.list_id,
                        name: row.list_name,
                        tasks: []
                    };
                    boardsMap[row.board_id].lists.push(list);
                }

                if (row.task_id) {
                    list.tasks.push({
                        task_id: row.task_id,
                        title: row.title,
                        description: row.description,
                        due_date: row.due_date,
                        completed: row.completed
                    });
                }
            }
        });

        const result = Object.values(boardsMap);
        res.json(result); // Return the structured data
    });
});

router.post('/boards', (req, res) => {
    const { name, user_id } = req.body; // Get name and user_id from the request body
  
    // Check if both name and user_id are provided
    if (!name || !user_id) {
      return res.status(400).json({ error: 'Name and user_id are required' });
    }
  
    const query = 'INSERT INTO Boards (name, user_id) VALUES (?, ?)';
  
    db.run(query, [name, user_id], function (err) {
      if (err) {
        return res.status(500).json({ error: 'Failed to create board' });
      }
      res.status(201).json({ board_id: this.lastID, name, user_id }); // Return created board info
    });
});

// POST /boards/:boardId/collaborators - Add a collaborator to a board
router.post('/boards/:boardId/collaborators', (req, res) => {
    const { boardId } = req.params; // Get the board ID from the URL
    const { userId } = req.body; // Get the userId from the request body

    // Check if the userId is provided
    if (!userId) {
        return res.status(400).json({ error: 'userId is required' });
    }

    const query = 'INSERT INTO BoardCollaborators (board_id, collaborator_id) VALUES (?, ?)';

    db.run(query, [boardId, userId], function(err) {
        if (err) {
            console.error('Error adding collaborator:', err);
            return res.status(500).json({ error: 'Failed to add collaborator' });
        }

        res.status(201).json({ message: 'Collaborator added successfully' });
    });
});

// DELETE /boards/:boardId/collaborators/:userId - Remove a collaborator from a board
router.delete('/boards/:boardId/collaborators/:userId', (req, res) => {
    const { boardId, userId } = req.params;
  
    const query = 'DELETE FROM BoardCollaborators WHERE board_id = ? AND collaborator_id = ?';
  
    db.run(query, [boardId, userId], function(err) {
      if (err) {
        console.error('Error removing collaborator:', err);
        return res.status(500).json({ error: 'Failed to remove collaborator' });
      }
  
      if (this.changes === 0) {
        return res.status(404).json({ error: 'Collaborator not found' });
      }
  
      res.status(200).json({ message: 'Collaborator removed successfully' });
    });
  });  

// GET /boards/:boardId/collaborators - Get all collaborators of a board
router.get('/boards/:boardId/collaborators', (req, res) => {
    const { boardId } = req.params; // Get the board ID from the URL

    const query = `
        SELECT u.user_id, u.username, u.email
        FROM Users u
        INNER JOIN BoardCollaborators bc ON u.user_id = bc.user_id
        WHERE bc.board_id = ?
    `;

    db.all(query, [boardId], (err, collaborators) => {
        if (err) {
            console.error('Error fetching collaborators:', err);
            return res.status(500).json({ error: 'Failed to fetch collaborators' });
        }

        res.json({ collaborators });
    });
});


module.exports = router;