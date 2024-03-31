import React, { useState, useEffect } from 'react';
import { verifyOTP, resendOTP } from './api/api'; // Import API functions for OTP verification and resend
import './Signup.css'; // Import CSS for styling

const OTPVerification = () => {
    const [otp, setOTP] = useState('');
    const [timer, setTimer] = useState(0);

    useEffect(() => {
        if (timer > 0) {
            const interval = setInterval(() => {
                setTimer(prevTimer => prevTimer - 1);
            }, 1000);

            return () => clearInterval(interval);
        }
    }, [timer]);

    const handleVerifyOTP = async () => {
        try {
            // Call API to verify OTP
            await verifyOTP(otp);
            // Handle successful verification
            console.log('OTP verified successfully');
        } catch (error) {
            // Handle verification error
            console.error('Failed to verify OTP:', error.message);
        }
    };

    const handleResendOTP = async () => {
        try {
            // Call API to resend OTP
            await resendOTP();
            // Reset timer for resend OTP
            setTimer(60); // Set timer to 60 seconds (1 minute)
        } catch (error) {
            // Handle resend OTP error
            console.error('Failed to resend OTP:', error.message);
        }
    };

    return (
        <div className="otp-container">
            <h2>OTP Verification</h2>
            <input
                className="otp-input"
                type="text"
                maxLength={4}
                value={otp}
                onChange={e => setOTP(e.target.value)}
            />
            <button className="otp-button" onClick={handleVerifyOTP}>Verify OTP</button>
            {timer === 0 ? (
                <button className="otp-button" onClick={handleResendOTP}>Resend OTP</button>
            ) : (
                <button className="otp-button" disabled>Resend OTP ({timer})</button>
            )}
        </div>
    );
};

export default OTPVerification;
