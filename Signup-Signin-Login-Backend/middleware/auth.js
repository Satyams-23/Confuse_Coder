//Auth.js

const jwt = require('jsonwebtoken');
const User = require('../models/User');

const isAuthentication = async (req, res, next) => {

    const token = req.headers.authorization;
    if (!token) {
        return res.status(401).json({ error: 'Unauthorized' });
    }
    try {

        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        const user = await User.findOne({ _id: decoded._id, token });

        if (!user) {
            return res.status(401).json({ error: 'Unauthorized' });
        }

        req.user = user;
        req.token = token;
        next();

    } catch (error) {
        console.error(error);
        res.status(401).json({ error: 'Unauthorized' });
    }

}

module.exports = isAuthentication;