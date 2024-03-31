const jwt = require('jsonwebtoken');
const User = require('../models/User');
const generateOTP = require('../utils/generateOTP');
const libphonenumber = require('libphonenumber-js');
const sendOTP = require('../utils/sendOTP');

const RegisterWithOtp = async (req, res) => {
    try {
        const { phoneNumber } = req.body;

        const phoneNumberObj = libphonenumber.parsePhoneNumberFromString(phoneNumber, 'IN');

        // Validate phone number
        if (!phoneNumberObj || !phoneNumberObj.isValid()) {
            return res.status(400).json({ error: 'Invalid phone number' });
        }

        // Check if user exists then login
        const login = await User.findOne({ phoneNumber });
        if (login) {
            return res.status(400).json({ error: 'User already exists' });
        }




        // Generate OTP
        const otp = await generateOTP();
        const otpExpires = Date.now() + 600000;

        // Send OTP via SMS
        await sendOTP(phoneNumber, 'OTP for account verification', `Your OTP is ${otp}`);




        // Store OTP data in session
        req.session.userData = {
            phoneNumber,
            otp,
            otpExpires
        };

        console.log('Result', req.session.userData);

        res.json({ message: 'OTP sent for verification', otp });
    } catch (error) {
        console.error('Error during login:', error);
        res.status(500).json({ error: 'Server error' });
    }
}

const resendOtp = async (req, res) => {
    try {
        const { phoneNumber } = req.session.userData;

        // Generate new OTP
        const otp = await generateOTP();
        const otpExpires = Date.now() + 600000;

        // Send OTP via SMS

        await sendOTP(phoneNumber, 'OTP for account verification', `Your OTP is ${otp}`);

        // Update OTP data in session
        req.session.userData = {
            phoneNumber,
            otp,
            otpExpires
        };

        await req.session.save();
        console.log('Result', req.session.userData);

        res.json({ message: 'OTP resent for verification', otp });
    } catch (error) {
        console.error('Error resending OTP:', error);
        res.status(500).json({ error: 'Server error' });
    }
}


const RegisterVerification = async (req, res) => {
    try {
        const { otp } = req.body;
        const data = req.session.userData;

        // Ensure session data contains the necessary properties
        if (!data || !data.phoneNumber || !data.otp || !data.otpExpires) {
            return res.status(400).json({ error: 'Session data is invalid or incomplete' });
        }

        // Convert stored OTP to string for comparison
        const storedOTP = data.otp.toString();
        const enteredOTP = otp.toString();

        // Validate OTP
        if (!enteredOTP) {
            return res.status(400).json({ error: 'Please provide OTP' });
        }

        // Check if OTP matches
        if (storedOTP !== enteredOTP) {
            return res.status(400).json({ error: 'Invalid OTP' });
        }

        // Check if OTP is expired
        if (data.otpExpires < Date.now()) {
            return res.status(400).json({ error: 'OTP expired' });
        }


        // Generate JWT token

        // Store token in session
        delete data.otp;
        delete data.otpExpires;

        // Save user data in database
        const user = new User({
            phoneNumber: data.phoneNumber,
        });

        const token = jwt.sign({ id: user._id }, process.env.JWT_SECRET);

        user.token = token;
        user.isVerified = true;
        user.role = 'patient';
        await user.save();



        res.json({ message: 'User logged in successfully', token });
    } catch (error) {
        console.error('Error during OTP verification:', error);
        res.status(500).json({ error: 'Server error' });
    }
};

const Login = async (req, res) => {
    try {
        const { phoneNumber } = req.body;

        const user = await User.findOne({
            phoneNumber
        });

        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }

        // Generate JWT token

        const token = jwt.sign({ id: user._id }, process.env.JWT_SECRET);

        // generate otp
        const otp = await generateOTP();
        const otpExpires = new Date(Date.now() + 1 * 60 * 1000 * 60 * 24);// 

        // Send OTP via email

        await sendOTP(phoneNumber, 'OTP for account verification', `Your OTP is ${otp}`);

        // Store OTP data in session
        req.session.userData = {
            phoneNumber,
            otp,
            otpExpires
        };

        await req.session.save();



        user.token = token;

        await user.save();

        res.json({ message: 'User logged in successfully', token });
    }
    catch (error) {
        console.error('Error during login:', error);
        res.status(500).json({ error: 'Server error' });
    }
}


const LoginWithOtpVerification = async (req, res) => {
    try {
        const { otp } = req.body;
        const data = req.session.userData;

        // Ensure session data contains the necessary properties
        if (!data || !data.phoneNumber || !data.otp || !data.otpExpires) {
            return res.status(400).json({ error: 'Session data is invalid or incomplete' });
        }

        // Convert stored OTP to string for comparison
        const storedOTP = data.otp.toString();
        const enteredOTP = otp.toString();

        // Validate OTP
        if (!enteredOTP) {
            return res.status(400).json({ error: 'Please provide OTP' });
        }

        // Check if OTP matches
        if (storedOTP !== enteredOTP) {
            return res.status(400).json({ error: 'Invalid OTP' });
        }

        // Check if OTP is expired
        if (data.otpExpires < Date.now()) {
            return res.status(400).json({ error: 'OTP expired' });
        }


        // Store token in session
        delete data.otp;
        delete data.otpExpires;


        res.json({ message: 'User login for OTP verification' });

    } catch (error) {
        console.error('Error during OTP verification:', error);
        res.status(500).json({ error: 'Server error' });
    }
}







module.exports = {
    RegisterWithOtp,
    RegisterVerification,
    resendOtp,
    Login,
    LoginWithOtpVerification
}
