//User model
const mongoose = require('mongoose');
const { Schema } = mongoose;

const userSchema = new Schema({
    email: {
        type: String,
        unique: true
    },
    phoneNumber: {
        type: Number,
    },

    password: {
        type: String,
    },
    username: {
        type: String,
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

    //two roles are there admin and user

    role: {
        type: String,
        default: ['patient', 'doctor']
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
