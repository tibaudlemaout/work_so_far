const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

// POST /register route to create a new user
router.post('/register', (req, res) => {
    const { username, email, password } = req.body;

    // Validate input
    if (!username || !email || !password) {
        return res.status(400).json({ error: 'Username, email, and password are required' });
    }

    const hashedPassword = bcrypt.hashSync(password, 10);
    const query = `INSERT INTO Users (username, email, password_hash) VALUES (?, ?, ?)`;

    db.run(query, [username, email, hashedPassword], function (err) {
        if (err) {
            console.error(err);
            return res.status(500).json({ error: 'User registration failed' });
        }
        res.status(200).json({ message: 'User registered successfully' });
    });
});

// POST /login route to authenticate users
router.post('/login', (req, res) => {
    const { email, password } = req.body;

    const query = `SELECT * FROM Users WHERE email = ?`;
    db.get(query, [email], (err, user) => {
        if (err || !user) {
            return res.status(401).json({ error: 'Invalid credentials' });
        }

        const isValidPassword = bcrypt.compareSync(password, user.password_hash);

        if (isValidPassword) {
            res.status(200).json({
                message: 'Login successful',
                userId: user.user_id,
                username: user.username,
                email: user.email
            });
        } else {
            res.status(401).json({ error: 'Invalid credentials' });
        }
    });
});

module.exports = router;