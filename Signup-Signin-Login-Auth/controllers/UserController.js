const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const User = require('../models/User');
const nodemailer = require('nodemailer');
const generateOTP = require('../utils/generateOTP');
// const sendEmail = require('../utils/sendEmail');


const SignupWithOtp = async (req, res) => {
    try {
        const { email, password, username } = req.body;

        // Validate input fields
        if (!email || !password || !username) {
            return res.status(400).json({ error: 'Please provide email, password, and username' });
        }

        // Check if user already exists
        const existingUser = await User.findOne({ email });
        if (existingUser) {
            return res.status(400).json({ error: 'User already exists' });
        }

        // Hash password
        const hashpassword = await bcrypt.hash(password, 10);

        // Generate OTP and set expiration time
        const otp = await generateOTP();
        const otpExpires = Date.now() + 600000;//

        // Set user data in session
        req.session.userData = {
            email,
            username,
            password: hashpassword,
            otp,
            otpExpires
        };

        // Send OTP via email
        // await sendEmail(email, otp);

        console.log('Result ', req.session.userData);

        res.json({ message: 'OTP sent for verification', otp: otp });
    } catch (error) {
        console.error('Error during sign-up:', error);
        res.status(500).json({ error: 'Server error' });
    }
}





const SignupWithOtpVerification = async (req, res) => {
    try {
        const { otp } = req.body;
        const data = req.session.userData;

        if (!data) {
            return res.status(400).json({ error: 'User not found' });
        }

        // Convert stored OTP to string for comparison
        const storedOTP = data.otp.toString();

        // Convert entered OTP to string for comparison
        const enteredOTP = otp.toString();

        if (storedOTP !== enteredOTP) {
            return res.status(400).json({ error: 'Invalid OTP' });
        }

        if (data.otpExpires < Date.now()) {
            return res.status(400).json({ error: 'OTP expired' });
        }

        //token
        const token = jwt.sign({ data: 'payload' }, process.env.JWT_SECRET, { expiresIn: '1h' });


        data.token = token;
        //delete otp and otpExpires from session and model
        delete data.otp;
        delete otp;
        delete data.otpExpires;





        const user = new User({
            email: data.email,
            password: data.password,
            username: data.username,
            token: data.token,
            isVerified: true
        });

        await user.save();

        res.json({ message: 'User registered successfully' });
    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }

}

const Signin = async (req, res) => {
    try {
        const { email, password } = req.body;
        const user = await User.findOne({
            email
        });

        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }

        const isMatch = await bcrypt.compare(password, user.password);

        if (!isMatch) {
            return res.status(400).json({ error: 'Invalid credentials' });
        }

        const token = jwt.sign({ data: 'payload' }, process.env.JWT_SECRET, { expiresIn: '1h' });


        user.token = token;

        await user.save();

        res.json({ message: 'User signed in successfully' });

    } catch (error) {

        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }

}

const resendotpforsignup = async (req, res) => {
    try {
        const { email } = req.session.userData;

        if (!email) {
            return res.status(400).json({ error: 'User not found' });
        }

        const otp = await generateOTP();
        const otpExpires = Date.now() + 60000;

        req.session.userData.otp = otp;
        req.session.userData.otpExpires = otpExpires;

        // Send OTP via email
        // await sendEmail(email, otp);

        res.json({ message: 'OTP sent for verification', otp: otp });
    } catch (error) {
        console.error('Error during OTP resend:', error);
        res.status(500).json({ error: 'Server error' });
    }

}




const Signout = async (req, res) => {
    try {
        const user = req.user;

        user.token = '';

        await user.save();

        res.json({ message: 'User signed out successfully' });

    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }
}
const forgotpassword = async (req, res) => {
    try {
        const { email } = req.body;
        const existingUser = await User.findOne({ email });
        if (!existingUser) {
            return res.status(400).json({ error: 'User not found' });
        }

        const otp = await generateOTP();
        const otpExpires = Date.now() + 60000;

        req.session.userData = {
            email,
            otp,
            otpExpires
        };

        // Send OTP via email
        // await sendEmail(email, otp);

        res.json({ message: 'OTP sent for password reset', otp: otp });
    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }
}

const resetpassword = async (req, res) => {
    try {
        const { otp, password, confirmpassword } = req.body;
        const data = req.session.userData;

        // Convert stored OTP to string for comparison
        const storedOTP = data.otp.toString();

        // Convert entered OTP to string for comparison
        const enteredOTP = otp.toString();

        // Check if the entered OTP matches the stored OTP
        if (storedOTP !== enteredOTP) {
            return res.status(400).json({ error: 'Invalid OTP' });
        }

        // Check if the stored OTP has expired
        if (req.session.userData.otpExpires < Date.now()) {
            return res.status(400).json({ error: 'OTP expired' });
        }

        // Check if the entered password matches the confirmed password
        if (password !== confirmpassword) {
            return res.status(400).json({ error: 'Passwords do not match' });
        }

        // Generate new password hash
        const hashpassword = await bcrypt.hash(password, 10);

        // Update user's password and remove userData from session

        const user = await User.findOne({ email: req.session.userData.email });

        user.password = hashpassword;

        console.log('User', user);


        delete req.session.userData;

        // Save user changes
        await user.save();

        // Send success message
        res.json({ message: 'Password reset successfully' });
    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }
}


const resendotpforforgotpassword = async (req, res) => {
    try {
        const { email } = req.session.userData;

        const user = await User.findOne({ email })
        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }

        const otp = await generateOTP();
        const otpExpires = Date.now() + 60000;

        req.session.userData = {
            email,
            otp,
            otpExpires
        };

        // Send OTP via email
        // await sendEmail(email, otp);

        res.json({ message: 'OTP sent for password reset', otp: otp });
    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }
}


module.exports = {
    SignupWithOtp,
    SignupWithOtpVerification,
    Signin,
    Signout,
    forgotpassword,
    resetpassword,
    resendotpforsignup,
    resendotpforforgotpassword
}



