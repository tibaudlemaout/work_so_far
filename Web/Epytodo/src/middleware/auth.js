const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');

module.exports = (req, res, next) => {
    const authHead = req.headers.authorization;
    const token = authHead && authHead.split(' ')[1];

    if (token === 'null')
        return res.status(403).json({"msg":"Token is not valid"});
    jwt.verify(token, process.env.SECRET, (err, user) => {
        if (err) {
            return res.status(401).json({"msg":"Token is not valid"});
        }
        req.user = user
        next();
    });
};