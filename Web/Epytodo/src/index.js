const express = require('express');
const bodyParser = require("body-parser")
const app = express();
const bcrypt = require('bcryptjs');
const port = process.env.PORT || 3000;

require('dotenv').config({path: "../.env"});

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

require('./routes/auth/auth')(app);
require('./routes/todos/todos')(app);
require('./routes/user/user')(app);

app.listen(port, () => {
    console.log(`App listening at http://localhost:${port}`);
});
