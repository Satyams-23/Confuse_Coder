const jwt = require('jsonwebtoken');
const User = require('../models/User');
const generateOTP = require('../utils/generateOTP');
const libphonenumber = require('libphonenumber-js');
const sendOTP = require('../utils/sendOTP');

const RegisterWithOtp = async (req, res) => {
    try {
        const { phoneNumber } = req.body;

        const phoneNumberObj = libphonenumber.parsePhoneNumberFromString(phoneNumber, 'IN');// 

        // Validate phone number
        if (!phoneNumberObj || !phoneNumberObj.isValid()) {
            return res.status(400).json({ error: 'Invalid phone number' });
        }

        // Check if user exists then login
        const login = await User.findOne({ phoneNumber, isVerified: true });

        if (login) {
            // Generate OTP
            const otp = await generateOTP();
            const otpExpires = Date.now() + 600000;

            // Send OTP via SMS
            await sendOTP(phoneNumber, 'OTP for account verification', `Your OTP is ${otp}`);

            login.otp = otp;
            login.otpExpires = otpExpires;
            await login.save();


            res.json({ message: 'OTP sent for verification', otp });
            return;

        }





        // Generate OTP
        const otp = await generateOTP();
        const otpExpires = Date.now() + 600000;

        // Send OTP via SMS
        await sendOTP(phoneNumber, 'OTP for account verification', `Your OTP is ${otp}`);

        const user = new User({
            phoneNumber,
            otp,
            otpExpires
        });

        await user.save();

        console.log('Result', req.session.userData);

        res.json({ message: 'OTP sent for verification', otp });
    } catch (error) {
        console.error('Error during login:', error);
        res.status(500).json({ error: 'Server error' });
    }
}

const resendOtp = async (req, res) => {
    try {
        const { phoneNumber } = req.body

        const user = await User.findOne({ phoneNumber });

        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }

        // Generate new OTP
        const otp = await generateOTP();
        const otpExpires = Date.now() + 600000;


        user.otp = otp;
        user.otpExpires = otpExpires;
        await user.save();



        // Send OTP via SMS

        await sendOTP(phoneNumber, 'OTP for account verification', `Your OTP is ${otp}`);



        console.log('Result', req.session.userData);

        res.json({ message: 'OTP resent for verification', otp });
    } catch (error) {
        console.error('Error resending OTP:', error);
        res.status(500).json({ error: 'Server error' });
    }
}


const RegisterVerification = async (req, res) => {
    try {
        const { otp, phoneNumber } = req.body;

        const data = await User.findOne({ phoneNumber });

        if (!data) {
            return res.status(400).json({ error: 'User not found' });
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




module.exports = {
    RegisterWithOtp,
    RegisterVerification,
    resendOtp,
}
