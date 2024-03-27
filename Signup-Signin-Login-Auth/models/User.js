//User model
const mongoose = require('mongoose');
const { Schema } = mongoose;

const userSchema = new Schema({
    email: {
        type: String,
        required: true,
        unique: true
    },
    password: {
        type: String,
        required: true
    },
    username: {
        type: String,
        required: true
    },
    otp: {
        type: String,

    },
    isVerified: {
        type: Boolean,
        default: false
    },
    date: {
        type: Date,
        default: Date.now
    },
    resetPasswordToken: {
        type: String
    },
    resetPasswordExpires: {
        type: Date
    },
    role: {
        type: String,
        default: 'user'
    },
    token: {
        type: String
    },
    otpExpires: {
        type: Date
    },
    confirmpassword: {
        type: String,
    }


});



module.exports = mongoose.model('User', userSchema);
