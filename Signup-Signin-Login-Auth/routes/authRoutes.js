
const UserController = require('../controllers/UserEmail');
const express = require('express');
const router = express.Router();

router.post('/signup', UserController.SignupWithOtp);
router.post('/signup/verify', UserController.SignupWithOtpVerification);
router.post('/signin', UserController.Signin);
router.post('/signout', UserController.Signout);
router.post('/resend-otp', UserController.resendotpforsignup);
router.post('/forgot-password', UserController.forgotpassword);
router.post('/reset-password', UserController.resetpassword);
router.post('/resend-otp-forgot-password', UserController.resendotpforforgotpassword);


module.exports = router;

