const express = require('express');
const axios = require('axios');
const sqlite3 = require('sqlite3').verbose();
require('dotenv').config();

const router = express.Router();

const db = new sqlite3.Database('../database/epitrello.db');

module.exports = router;