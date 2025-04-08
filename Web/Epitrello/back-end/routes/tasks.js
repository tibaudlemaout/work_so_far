const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

// POST /tasks - Create a new task
router.post('/tasks', (req, res) => {
    const { title, description, due_date, list_id } = req.body;

    if (!title || !list_id) {
        return res.status(400).json({ error: 'Title and list_id are required' });
    }

    const query = 'INSERT INTO Tasks (title, description, due_date, list_id) VALUES (?, ?, ?, ?)';

    db.run(query, [title, description, due_date, list_id], function(err) {
        if (err) {
            return res.status(500).json({ error: 'Failed to create task' });
        }
        res.status(201).json({ task_id: this.lastID, title, description, due_date, list_id });
    });
});

// PUT /tasks/:taskId - Update a task
router.put('/tasks/:taskId', (req, res) => {
    const { taskId } = req.params; // Get the taskId from the URL
    const { title, description, due_date, list_id } = req.body; // Get the data from the request body

    const query = `UPDATE Tasks SET 
                   title = COALESCE(?, title), 
                   description = COALESCE(?, description), 
                   due_date = COALESCE(?, due_date), 
                   list_id = COALESCE(?, list_id)
                   WHERE task_id = ?`;

    db.run(query, [title, description, due_date, list_id, taskId], function(err) {
        if (err) {
            console.error('Error updating task:', err);
            return res.status(500).json({ error: 'Failed to update task' });
        }

        if (this.changes === 0) {
            console.log('No task found with ID:', taskId);
            return res.status(404).json({ error: 'Task not found' });
        }

        console.log('Task updated successfully');
        res.status(200).json({ message: 'Task updated successfully' });
    });
});

// DELETE /tasks/:taskId - Delete a task
router.delete('/tasks/:taskId', (req, res) => {
    const { taskId } = req.params; // This will capture the task ID from the URL
    console.log(`Received request to delete task with ID: ${taskId}`); // Log for debugging

    const query = 'DELETE FROM Tasks WHERE task_id = ?'; // Update query to use task_id
    db.run(query, [taskId], function(err) {
        if (err) {
            console.error('Error deleting task:', err);
            return res.status(500).json({ error: 'Failed to delete task' });
        }

        if (this.changes === 0) {
            console.log('No task found with ID:', taskId);
            return res.status(404).json({ error: 'Task not found' });
        }

        console.log('Task deleted successfully');
        res.status(200).json({ message: 'Task deleted successfully' });
    });
});

// PUT /tasks/:taskId/move - Move a task to a different list
router.put('/tasks/:taskId/move', (req, res) => {
    const { taskId } = req.params;
    const { newListId, newPosition } = req.body;

    if (!newListId) {
        return res.status(400).json({ error: 'newListId is required' });
    }
    const query = `
        UPDATE Tasks 
        SET list_id = ?, position = COALESCE(?, position) 
        WHERE task_id = ?
    `;
    db.run(query, [newListId, newPosition, taskId], function (err) {
        if (err) {
            console.error('Error moving task:', err);
            return res.status(500).json({ error: 'Failed to move task' });
        }
        if (this.changes === 0) {
            return res.status(404).json({ error: 'Task not found' });
        }

        res.status(200).json({ message: 'Task moved successfully' });
    });
});

module.exports = router;