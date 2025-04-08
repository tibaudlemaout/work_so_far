const express = require('express');
const axios = require('axios');
const sqlite3 = require('sqlite3').verbose();
require('dotenv').config();

const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

// Temporary storage (Use a DB in production)
let githubAccessToken = null;
router.get('/github/callback', async (req, res) => {
    const code = req.query.code;
    if (!code) {
        return res.status(400).json({ error: 'Authorization code missing' });
    }

    try {
        // Exchange code for access token
        const response = await axios.post('https://github.com/login/oauth/access_token', {
            client_id: process.env.GITHUB_CLIENT_ID,
            client_secret: process.env.GITHUB_CLIENT_SECRET,
            code: code,
        }, {
            headers: { 'Accept': 'application/json' }
        });

        // Get the access token from the response
        const githubAccessToken = response.data.access_token;
        if (!githubAccessToken) {
            return res.status(400).json({ error: 'Failed to get access token' });
        }

        console.log('GitHub Access Token:', githubAccessToken);

        // Save the token in the database (TokenStorage table)
        db.run('INSERT INTO TokenStorage (token) VALUES (?)', [githubAccessToken], function(err) {
            if (err) {
                console.error('Error saving token:', err.message);
                return res.status(500).json({ error: 'Failed to save token in database' });
            }
            console.log('Token saved to database');
        });

        // Send success response
        res.json({ message: 'GitHub authentication successful', access_token: githubAccessToken });
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: 'GitHub authentication failed' });
    }
});

// Route to test issue creation
router.post('/github/create-issue', async (req, res) => {
    // Retrieve token from the database (for simplicity, assuming the token is stored in the first row)
    db.get('SELECT token FROM TokenStorage WHERE id = 1', async (err, row) => {
        if (err) {
            console.error('Error retrieving token:', err.message);
            return res.status(500).json({ error: 'Failed to retrieve token' });
        }
        
        const githubAccessToken = row?.token;
        if (!githubAccessToken) {
            return res.status(401).json({ error: 'Missing GitHub access token. Authenticate first.' });
        }

        const { owner, repo, title, body } = req.body;

        try {
            const response = await axios.post(`https://api.github.com/repos/tibaudlemaout/epitrellorepo/issues`, 
                { title, body },
                {
                    headers: {
                        'Authorization': `Bearer ${githubAccessToken}`,
                        'Accept': 'application/vnd.github.v3+json'
                    }
                }
            );

            res.json({ message: 'Issue created', issue: response.data });
        } catch (error) {
            console.error(error.response?.data || error.message);
            res.status(500).json({ error: 'Failed to create GitHub issue' });
        }
    });
});

router.get('/get-github-token', async (req, res) => {
    const token = await getGitHubToken();
    res.json({ token });
  });

  async function getGitHubToken() {
    return new Promise((resolve, reject) => {
      // Query to select the latest token from the correct table
      db.get('SELECT token FROM TokenStorage ORDER BY id DESC LIMIT 1', [], (err, row) => {
        if (err) {
          console.error('Error fetching token:', err);
          reject(err);
        } else {
          if (row) {
            // Return the token from the latest row
            resolve(row.token);
          } else {
            console.log('No token found in the database.');
            resolve(null);
          }
        }
      });
    });
  }

module.exports = router;
