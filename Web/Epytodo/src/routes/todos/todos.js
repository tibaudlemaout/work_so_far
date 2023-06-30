const {create_todo, all_todo, todo_id, delete_task_id, update_task_id} = require('./todos.query');
const auth = require('../../middleware/auth');
const verif_id = require('../../middleware/notFound');
const bcrypt = require('bcryptjs');

module.exports = function(app) {
    app.get('/todos', auth, (req, res) => {
        all_todo(res);
    });

    app.get('/todos/:id', auth, verif_id, (req, res) => {
        const todo_id = req.params.id;

        todo_id(res, todo_id);
    });

    app.post('/todos', auth, (req, res) => {
        const title = req.body.title;
        const description = req.body.description;
        const due_time = req.body.due_time;
        const user_id = req.body.user_id;
        const status = req.body.status;

        if (title === undefined || description === undefined  ||
        due_time === undefined || user_id === undefined || status === undefined) {
            res.status(500).json({"msg":"internal server error"});
            return;
        }
        create_todo(res, title, description, due_time, user_id, status);
    });

    app.delete('/todos/:id', auth, (req, res) => {
        const todo_id = req.params.id;

        delete_task_id(res, todo_id);
    });

    app.put('/todos/:id', auth, (req, res) => {
        const todo_id = req.params.id;
        const title = req.body.title;
        const description = req.body.description;
        const due_time = req.body.due_time;
        const user_id = req.body.user_id;
        const status = req.body.status;

        if (todo_id === undefined || title === undefined || description === undefined  ||
        due_time === undefined || user_id === undefined ||
        status === undefined) {
            res.status(500).json({"msg":"internal server error"});
            return;
        }
        update_task_id(res, todo_id, title, description, due_time, user_id, status);
    })
}