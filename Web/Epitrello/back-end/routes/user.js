const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

// Add a route to get the userId by email
router.get('/users/email/:email', (req, res) => {
    const { email } = req.params;

    const { boardId } = req.params;
    const { userId } = req.body;

    const query = 'SELECT user_id FROM Users WHERE email = ?';
    db.get(query, [email], (err, row) => {
        if (err) {
            console.error('Error fetching user by email:', err);
            return res.status(500).json({ error: 'Failed to retrieve user' });
        }

        if (!row) {
            return res.status(404).json({ error: 'User not found' });
        }

        res.json({ user_id: row.user_id });
    });
});

router.put('/update-username', async (req, res) => {
    const { user_id, new_username } = req.body;
    
    if (!user_id || !new_username) {
      return res.status(400).json({ message: 'Invalid input' });
    }

    console.log('Request received: ', { user_id, new_username });

    try {
      // Update the username in the database
      const result = await db.query(
        'UPDATE Users SET username = $1 WHERE user_id = $2 RETURNING *',
        [new_username, user_id]
      );
      console.log('Database query result: ', result);

      if (result.rowCount > 0) {
        return res.status(200).json({ message: 'Username updated successfully' });
      } else {
        return res.status(404).json({ message: 'User not found' });
      }
    } catch (error) {
      console.error('Error updating username: ', error); // Log the error if any
      return res.status(500).json({ message: 'Internal server error' });
    }
});

module.exports = router;