const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

// POST /lists - Create a new list
router.post('/lists', (req, res) => {
    const { name, board_id } = req.body;

    if (!name || !board_id) {
        return res.status(400).json({ error: 'Name and board_id are required' });
    }

    const query = 'INSERT INTO Lists (name, board_id) VALUES (?, ?)';

    db.run(query, [name, board_id], function(err) {
        if (err) {
            return res.status(500).json({ error: 'Failed to create list' });
        }
        res.status(201).json({ list_id: this.lastID, name, board_id });
    });
});

module.exports = router;