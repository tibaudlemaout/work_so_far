const {register, check_acc_email, get_acc_email} = require('./../user/user.query');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');

module.exports = function(app) {

    app.post('/register', (req, res) => {
        const email = req.body.email;
        const name = req.body.name;
        const firstname = req.body.firstname;
        const password = req.body.password;

        if (email === undefined || name === undefined || firstname === undefined || password === undefined) {
           return res.status(400).json({ "msg": 'Bad parameter' });
        }

        const hashedPassword = jwt.sign({ email: email, password: password }, process.env.SECRET, {algorithm: 'HS256'}, { expiresIn: '3h' });

        check_acc_email(res, email, function(nbr) {
            if (nbr == 84) {
                res.status(409).json({"msg":"account already exist"});
                return;
            } else {
                register(res, email, hashedPassword, name, firstname);
                return;
            }
        });

    });

    app.post('/login', (req, res) => {
        const email = req.body.email;
        const password = req.body.password;

        if (email === undefined || password === undefined) {
          return res.status(500).json({ "msg": 'Internal server error' });
        }

        get_acc_email(res, email, password, bcrypt, function(nbr) {
            if (nbr == 84) {
                res.status(401).json({"msg":"Invalid Credentials"});
            }
            return;
        });
    });
}
