const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const User = require('../models/User');
const generateOTP = require('../utils/generateOTP');
const sendEmail = require('../utils/senEmail');

const SignupWithOtp = async (req, res) => {
    try {
        const { email, password, username } = req.body;

        // Validate input fields
        if (!email || !password || !username) {
            return res.status(400).json({ error: 'Please provide email, password, and username' });
        }

        // Check if user already exists
        const existingUser = await User.findOne({ email, isVerified: true });
        if (existingUser) {
            return res.status(400).json({ error: 'User already exists with this email address' });
        }

        // Hash password
        const hashpassword = await bcrypt.hash(password, 10);

        // Generate OTP and set expiration time
        const otp = await generateOTP();
        const otpExpires = new Date(Date.now() + 1 * 60 * 1000 * 60 * 1);

        // create a user object 
        const newUser = new User({
            email,
            password: hashpassword,
            username,
            otp,
            otpExpires,
            isVerified: false
        });

        await newUser.save();

        // Send OTP via email
        await sendEmail(email, 'OTP for account verification', `Your OTP is ${otp}`);

        res.json({ message: 'OTP sent for verification', otp: otp });
    } catch (error) {
        console.error('Error during sign-up:', error);
        res.status(500).json({ error: 'Server error' });

    }
};
const SignupWithOtpVerification = async (req, res) => {
    try {
        const { otp, email } = req.body;

        // console.log('otp and email', otp, email);

        const data = await User.findOne({ email });

        console.log('data', data);

        if (!data) {
            return res.status(400).json({ error: 'User not found' });
        }



        let storedOTP = data.otp.toString();
        let enteredOTP = otp.toString();

        if (storedOTP !== enteredOTP) {
            return res.status(400).json({ error: 'Invalid OTP' });
        }

        if (new Date(data.otpExpires) < Date.now()) {
            return res.status(400).json({ error: 'OTP expired' });
        }


        // Generate JWT token
        const token = jwt.sign({ data: 'payload' }, process.env.JWT_SECRET, { expiresIn: '1h' });

        // Update user object with token and verification status
        data.token = token;
        data.isVerified = true;

        // Remove OTP and expiration fields
        data.otp = undefined;
        data.otpExpires = undefined;

        // Save updated user object
        await data.save();

        res.json({ message: 'User verified successfully', token });
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: 'Server error' });
    }
};

const Signin = async (req, res) => {
    try {
        const { email, password } = req.body;
        const user = await User.findOne({
            email, isVerified: true
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
        const { email } = req.body;

        const user = await User.findOne({ email });
        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }

        if (!user.email) {
            return res.status(400).json({ error: 'Email not found' });
        }

        const otp = await generateOTP();
        const otpExpires = new Date(Date.now() + 1 * 60 * 1000 * 60 * 24);

        user.otp = otp;
        user.otpExpires = otpExpires;

        await user.save();

        await sendEmail(email, 'OTP for account verification', `Your OTP is ${otp}`);

        res.json({ message: 'OTP sent for verification', otp: otp });

    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });

    }

}







const Signout = (req, res) => {


    try {


        req.user.token = '';
        req.user.save();
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
        const otpExpires = new Date(Date.now() + 1 * 60 * 1000 * 60 * 24);

        existingUser.otp = otp;
        existingUser.otpExpires = otpExpires;

        await existingUser.save();



        // Send OTP via email
        await sendEmail(email, 'OTP for password reset', `Your OTP is ${otp}`);


        res.json({ message: 'OTP sent for password reset', otp: otp });
    } catch (error) {
        console.log(error);
        res.status(500).json({ error: 'Server error' });
    }
}



const resetpassword = async (req, res) => {
    try {
        const { otp, email, password, confirmpassword } = req.body;

        const user = await User.findOne({ email });

        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }



        // Convert stored OTP to string for comparison
        const storedOTP = user.otp.toString();

        // Convert entered OTP to string for comparison
        const enteredOTP = otp.toString();

        // Check if the entered OTP matches the stored OTP
        if (storedOTP !== enteredOTP) {
            return res.status(400).json({ error: 'Invalid OTP' });
        }

        // Check if the stored OTP has expired
        if (user.otpExpires < Date.now()) {
            return res.status(400).json({ error: 'OTP expired' });
        }

        // Check if the entered password matches the confirmed password
        if (password !== confirmpassword) {
            return res.status(400).json({ error: 'Passwords do not match' });
        }

        // Generate new password hash
        const hashpassword = await bcrypt.hash(password, 10);


        user.password = hashpassword;
        delete user.otp;
        delete user.otpExpires;



        console.log('User', user);



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
        const { email } = req.body;

        const user = await User.findOne({ email, isVerified: true })
        if (!user) {
            return res.status(400).json({ error: 'User not found' });
        }

        const otp = await generateOTP();
        const otpExpires = new Date(Date.now() + 1 * 60 * 1000 * 60 * 24);

        user.otp = otp;
        user.otpExpires = otpExpires;

        await user.save();

        await sendEmail(email, 'OTP for password reset', `Your OTP is ${otp}`);

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



