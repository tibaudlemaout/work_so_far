const db = require('../../config/db');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcrypt');

exports.register = function (res, email, password, name, firstname) {
    db.query(
      `INSERT INTO user (email, password, name, firstname) VALUES ("${email}", "${password}", "${name}", "${firstname}")`, function (err, results, fields) {
        if (err) {
          res.status(500).json({ "msg": 'Internal server error' });
        } else {
          const token = jwt.sign({ email: email, password: password }, process.env.SECRET, {algorithm: 'HS256'}, { expiresIn: '3h' });
          res.status(200).json({ "token": token });
        }
      }
    );
  };

  exports.get_user = function (req, res) {
    try {
      const token = req.header('token');
      const decodedToken = jwt.verify(token, process.env.SECRET);
      const email = decodedToken.email;
  
      db.query('SELECT * FROM user WHERE email = ?', [email], function (err, results, fields) {
        if (err) {
          res.status(500).json({ "msg": 'Internal server error' });
        } else {
          res.status(200).json(results);
        }
      });
    } catch (err) {
      res.status(401).json({ "msg": 'Invalid token' });
    }
  };

exports.get_all_user = function (res) {
    db.query('SELECT * FROM user', function (err, results, fields) {
      if (err) {
        res.status(500).json({ "msg": 'Internal server error' });
      } else {
        res.status(200).json(results);
      }
    });
};

exports.get_all_todo = function (res, id) {
    db.query(`SELECT * FROM todo WHERE user_id = "${id}"`, function (err, results, fields) {
      if (err) {
        res.status(500).json({ "msg": 'Internal server error' });
      } else {
        res.status(200).json(results);
      }
    });
};

exports.get_id_or_mail = function (res, data) {
    if (data.includes('@')) {
      db.query(`SELECT * FROM user WHERE email = "${data}"`, function (err, results, fields) {
        if (err) {
          res.status(500).json({ "msg": 'Internal server error' });
        } else {
          if (results.length > 0) {
            res.status(200).json(results);
          } else {
            res.status(404).json({ "msg": 'Not found' });
          }
        }
      });
    } else {
      db.query(`SELECT * FROM user WHERE id = "${data}"`, function (err, results, fields) {
        if (err) {
          res.status(500).json({ "msg": 'Internal server error' });
        } else {
          if (results.length > 0) {
            res.status(200).json(results);
          } else {
            res.status(404).json({ "msg": 'Not found' });
          }
        }
      });
    }
  };

  exports.get_acc_email = function (res, email, password) {
    db.query(`SELECT password, id FROM user WHERE email = "${email}"`, function (err, results, fields) {
      if (err) {
        res.status(500).json({ "msg": 'Internal server error' });
      } else {
        if (results.length > 0) {
          const passwordHash = results[0].password;
          const id = results[0].id;
          const hashedPassword = jwt.sign({ email: email, password: password }, process.env.SECRET, {algorithm: 'HS256'}, { expiresIn: '3h' });
          if (passwordHash === hashedPassword) {
            const token = jwt.sign({ email: email, password: password }, process.env.SECRET, {algorithm: 'HS256'}, { expiresIn: '3h' });
            res.status(200).json({ "token": token });
          } else {
            res.status(401).json({ "msg": "Invalid Credentials" });
            return(84);
          }
        } else {
          res.status(404).json({ "msg": 'Not found' });
        }
      }
    });
  };

  exports.check_acc_name = function (res, name) {
    db.query(`SELECT * FROM user WHERE name = "${name}"`, function (err, results, fields) {
      if (err) {
        res.status(500).json({ "msg": 'Internal server error' });
      }
    });
  };


exports.check_acc_email = function (res, email, callback) {
  db.query(`SELECT * FROM user WHERE email = "${email}"`, function (err, results, fields) {
    if (err) {
      return res.status(500).json({ "msg": 'Internal server error' });
    }
    if (results.length > 0) {
      return(84);
    } else {
      return(0);
    }
  });
};


  exports.delete_user_id = function (res, id) {
    db.query(`DELETE FROM user WHERE id = "${id}"`, function (err, results, fields) {
      if (err) {
        res.status(500).json({ "msg": 'Internal server error' });
      } else {
        res.status(200).json({ "msg": `Successfully deleted record number : ${id}` });
      }
    });
  };

  exports.update_user_id = function (res, id, email, password, name, firstname) {
    db.query(
      `UPDATE user SET email = "${email}", password = "${password}", name = "${name}", firstname = "${firstname}" WHERE id = "${id}"`, function (err, results, fields) {
        if (err) {
          res.status(500).json({ "msg": 'Internal server error' });
        } else {
          db.execute(`SELECT id, email, password, created_at, firstname, name FROM user WHERE id = "${id}"`, function (
            err,
            results,
          ) {
            if (err) {
              res.status(500).json({ "msg": 'Internal server error' });
            } else {
              res.status(200).json(results);
            }
          });
        }
      }
    );
  };
  
