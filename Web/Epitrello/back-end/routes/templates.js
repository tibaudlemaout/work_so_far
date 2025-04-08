const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

router.post('/template-boards', (req, res) => {
    const { name, user_id, template_id } = req.body;

    if (!name || !user_id) {
        return res.status(400).json({ error: 'Name and user_id are required' });
    }

    // Step 1: Create the board
    const boardQuery = 'INSERT INTO Boards (name, user_id) VALUES (?, ?)';

    db.run(boardQuery, [name, user_id], function (err) {
        if (err) {
            return res.status(500).json({ error: 'Failed to create board' });
        }

        const boardId = this.lastID; // Get the newly created board ID

        // Step 2: Fetch predefined lists for the selected template
        if (template_id) {
            const templateLists = getTemplateLists(template_id); // Fetch predefined lists

            // Insert predefined lists into the database
            const listQuery = 'INSERT INTO Lists (name, board_id) VALUES (?, ?)';
            const stmt = db.prepare(listQuery);

            templateLists.forEach((listName) => {
                stmt.run([listName, boardId]);
            });

            stmt.finalize(); // Close prepared statement
        }

        // Respond with the created board
        res.status(201).json({ board_id: boardId, name, user_id });
    });
});

// Helper function to fetch predefined lists based on template_id
function getTemplateLists(template_id) {
    const templates = {
        1: ['To Do', 'In Progress', 'Done'],
        2: ['Backlog', 'Current Sprint', 'Completed'], 
        3: ['Ideas', 'Development', 'Testing', 'Launch'],
    };

    return templates[template_id] || [];
}

module.exports = router;