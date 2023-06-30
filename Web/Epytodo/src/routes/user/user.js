const {get_all_user, get_user, get_all_todo, get_id_or_mail, delete_user_id, update_user_id} = require('./user.query');
const auth = require('../../middleware/auth');
const jwt = require('jsonwebtoken');

module.exports = function(app) {
    app.get('/user', auth, (req, res) => {
        get_user(req, res);
    });

    app.get('/user/todos', auth, (req, res) => {
        get_all_todo(res, req.user);
    });

    app.get('/users/:data', auth, (req, res) => {
        const data = req.params.data;
        get_id_or_mail(res, data);
    });

    app.delete('/users/:id', auth, (req, res) => {
        const user_id = req.params.id;
        delete_user_id(res, user_id);
    });

    app.put('/users/:id', auth, (req, res) => {
        const user_id = req.params.id;
        const email = req.body.email;
        const name = req.body.name;
        const firstname = req.body.firstname;
        const password = req.body.password;

        if (user_id === undefined || email === undefined || name === undefined  ||
        firstname === undefined || password === undefined) {
            res.status(500).json({"msg":"internal server error"});
            return;
        }
        const hashedPassword = jwt.sign({ email: email, password: password }, process.env.SECRET, {algorithm: 'HS256'}, { expiresIn: '3h' });
        update_user_id(res, user_id, email, hashedPassword, name, firstname);
    });
}