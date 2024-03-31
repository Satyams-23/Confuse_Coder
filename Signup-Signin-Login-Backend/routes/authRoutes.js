
const UserController = require('../controllers/UserEmail');
const UserPhoneNumber = require('../controllers/UserPhoneNumber');
const express = require('express');
const router = express.Router();

//email
router.post('/signup', UserController.SignupWithOtp);
router.post('/signup/verify', UserController.SignupWithOtpVerification);
router.post('/signin', UserController.Signin);
router.post('/signout', UserController.Signout);
router.post('/signin/resendotp', UserController.resendotpforsignup);
router.post('/forgot-password', UserController.forgotpassword);
router.post('/reset-password', UserController.resetpassword);
router.post('/forgot-password/resendotp', UserController.resendotpforforgotpassword);

//phone number
router.post('/register', UserPhoneNumber.RegisterWithOtp);
router.post('/register/verify', UserPhoneNumber.RegisterVerification);
router.post('/register/resendotp', UserPhoneNumber.resendOtp);
router.post('/login', UserPhoneNumber.Login);
router.post('/login/resendotp', UserPhoneNumber.resendOtp);
router.post('/login/verify', UserPhoneNumber.LoginWithOtpVerification);



module.exports = router;

