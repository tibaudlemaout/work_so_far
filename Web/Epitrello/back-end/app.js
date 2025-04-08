const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const axios = require('axios');
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const cors = require('cors');
const app = express();

const authRoutes = require('./routes/register');
const userRoutes = require('./routes/user');
const notifRoutes = require('./routes/notifications');
const listRoutes = require('./routes/lists');
const boardRoutes = require('./routes/board');
const taskRoutes = require('./routes/tasks');
const templateRoutes = require('./routes/templates');
const githubRoutes = require('./routes/githubAuth');

const db = new sqlite3.Database('../database/epitrello.db');

app.use(bodyParser.json());

// Enable CORS for all routes
app.use(cors());

app.use('/', authRoutes);
app.use('/', userRoutes);
app.use('/', notifRoutes);
app.use('/', listRoutes);
app.use('/', boardRoutes);
app.use('/', taskRoutes);
app.use('/', templateRoutes);
app.use('/', githubRoutes);

const port = 3000;
app.listen(port, () => {
    console.log(`Server running on port ${port}`);
});
