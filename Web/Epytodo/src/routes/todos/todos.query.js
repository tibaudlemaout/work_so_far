const db = require('../../config/db');
const jwt = require('jsonwebtoken');

exports.all_todo = function(res) {
    db.query(`SELECT * FROM todo`, function(err, results, fields) {
        if (err) {
            res.status(500).json({ "msg": "Internal server error" });
        } else {
            res.status(200).json(results);
        }
    });
}

exports.todo_id = function(res, id) {
    db.execute(`SELECT * FROM todo WHERE id = "${id}"`, function(err, results, fields) {
        if (err) {
            res.status(500).json({ error: err.message });
        } else {
            if (results.length > 0) {
                res.status(200).json(results);
            } else {
                res.status(404).json({ "msg": 'Not found' });
            }
        }
    });
}

exports.create_todo = function(res, title, description, due_time, id, status) {
    db.execute(`INSERT INTO todo (title, description, due_time, status, user_id) VALUES ("${title}", "${description}", "${due_time}", "${status}", "${user_id}")`, function(err, results, fields) {
        if (err) {
            res.status(500).json({ error: err.message });
        } else {
            const id_task = res.insertId
            db.execute('SELECT * FROM `todo` WHERE id = ?', [id_task], function(err, results, fields) {
                if (err) {
                    res.status(500).json({ "msg": 'Internal server error' });
                } else {
                    res.status(200).json(results);
                }
            });
        }
    });
}

exports.delete_task_id = function(res, id) {
    db.execute(`DELETE FROM todo WHERE id = "${id}"`, function(err, results, fields) {
        if (err) {
            res.status(500).json({ error: err.message });
        } else {
            if (results.affectedRows > 0) {
                res.status(200).json({ "msg": `Successfully deleted record number: ${id}` });
            } else {
                res.status(404).json({ "msg": 'Not found' });
            }
        }
    });
}

exports.update_task_id = function(res, id, title, desc, due_time, user_id, status) {
    db.execute(`UPDATE todo SET title = "${title}", description = "${description}", due_time = "${due_time}", user_id = "${user_id}", status = "${status}" WHERE id = "${id}"`, function(err, results, fields) {
        if (err) {
            res.status(500).json({ "msg": 'Internal server error' });
        } else {
            db.execute(`SELECT id, title, description, created_at, due_time, user_id, status FROM todo WHERE id = "${id}"`, function(err, results, fields) {
                if (err) {
                    res.status(500).json({ "msg": 'Internal server error' });
                } else {
                    if (results.length > 0) {
                        res.status(200).json(results);
                    } else {
                        res.status(404).json({ "msg": 'Todo not found' });
                    }
                }
            });
        }
    });
}