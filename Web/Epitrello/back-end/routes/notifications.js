const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

router.get('/notifications/:userId', async (req, res) => {
    const { userId } = req.params;
    console.log(`Fetching notifications for userId: ${userId}`);
    try {
        const query = `SELECT * FROM Notifications WHERE user_id = ? ORDER BY created_at DESC`;
        const params = [userId];
        
        db.all(query, params, (err, rows) => {
            if (err) {
                console.error('Database query error:', err);
                res.status(500).json({ success: false, error: 'Failed to fetch notifications.' });
                return;
            }

            console.log('Fetched notifications:', rows);
            res.json({ success: true, notifications: rows });
        });
    } catch (err) {
        console.error('Error fetching notifications:', err);
        res.status(500).json({ success: false, error: 'Failed to fetch notifications.' });
    }
});

router.post('/create-notification', async (req, res) => {
    const { userId, type, relatedId, message } = req.body;
  
    const query = `
      INSERT INTO Notifications (user_id, type, related_id, message)
      VALUES (?, ?, ?, ?)
    `;
    
    try {
      await db.run(query, [userId, type, relatedId, message]);
      res.json({ success: true });
    } catch (error) {
      console.error(error);
      res.status(500).json({ success: false, message: 'Failed to create notification' });
    }
});

router.post('/notifications/:id/mark-as-read', async (req, res) => {
    const notificationId = req.params.id;

    try {
        await db.run(
        `UPDATE notifications SET read = 1 WHERE notification_id = ?`,
        [notificationId]
        );
        res.status(200).json({ success: true, message: 'Notification marked as read.' });
    } catch (err) {
        console.error(err);
        res.status(500).json({ success: false, message: 'Failed to update notification.' });
    }
});

module.exports = router;