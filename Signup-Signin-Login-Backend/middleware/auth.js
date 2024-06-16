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


// Middleware to delete unverified users older than 1 hour
const deleteUnverifiedUsers = async (req, res, next) => {

    try {

        // Calculate the timestamp 1 hour ago
        const oneHourAgo = new Date(Date.now() - 60 * 60 * 1000);

        // Find unverified users created more than 1 hour ago
        const unverifiedUsers = await User.find({ isVerified: false, date: { $lt: oneHourAgo } });

        // Delete unverified users
        await Promise.all(unverifiedUsers.map(user => user.deleteOne()));

        console.log('Unverified users deleted:', unverifiedUsers.length);
    } catch (error) {
        console.error('Error deleting unverified users:', error);
    }

    next();
};



module.exports = { isAuthentication, deleteUnverifiedUsers };