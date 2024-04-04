import React, { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import './Signup.css'; // Import CSS file for styling
import axios from 'axios'; // Assuming using axios for API calls

const Signup = () => {
    const [stage, setStage] = useState('signup'); // Current stage (signup, verify, resend)
    const [userData, setUserData] = useState({
        email: '',
        password: '',
        username: '',
    });
    const [otp, setOtp] = useState('');
    const [errorMessage, setErrorMessage] = useState(null);
    const [successMessage, setSuccessMessage] = useState(null);
    const [isLoading, setIsLoading] = useState(false);
    const [resendDisabled, setResendDisabled] = useState(false);
    const [resendCountdown, setResendCountdown] = useState(0);
    let verificationTimer; // Declare verificationTimer variable here

    const handleChange = (e) => {
        setUserData({ ...userData, [e.target.name]: e.target.value });
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        setIsLoading(true);
        setErrorMessage(null);
        setSuccessMessage(null);

        try {
            if (stage === 'signup') {
                const response = await axios.post('http://localhost:5000/api/v1/signup', userData);
                console.log('Signup response:', response.data);
                setStage('verify');
                startVerificationCountdown(); // Start verification countdown when transitioning to verify stage
            } else if (stage === 'verify') {
                const response = await axios.post('http://localhost:5000/api/v1/signup/verify', { otp, email: userData.email });
                console.log('Verification response:', response.data);
                setSuccessMessage('Verification successful');
                clearInterval(verificationTimer); // Stop verification countdown upon successful verification
            }
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Signup failed');
        } finally {
            setIsLoading(false);
        }
    };

    const handleResendOtp = async () => {
        setOtp('');
        setResendDisabled(true);
        setResendCountdown(60); // Set countdown to 60 seconds

        // Start countdown timer for resend OTP
        const resendTimer = setInterval(() => {
            setResendCountdown((prevCountdown) => {
                if (prevCountdown === 1) {
                    clearInterval(resendTimer);
                    setResendDisabled(false);
                    return 0;
                }
                return prevCountdown - 1;
            });
        }, 1000);

        // Send request to resend OTP
        try {
            const response = await axios.post('http://localhost:5000/api/v1/resendotp', { email: userData.email });
            console.log('Resend OTP response:', response.data);
            setSuccessMessage('New OTP sent successfully');
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Failed to resend OTP');
        }
    };

    // Function to start the verification countdown
    const startVerificationCountdown = () => {
        verificationTimer = setInterval(() => {
            setResendCountdown((prevCountdown) => {
                if (prevCountdown === 1) {
                    clearInterval(verificationTimer);
                    return 0;
                }
                return prevCountdown - 1;
            });
        }, 1000);
    };

    useEffect(() => {
        // Handle countdown completion
        if (resendCountdown === 0 && stage === 'resend') {
            setStage('verify'); // Return to verify stage after resend countdown completion
        }

        // Clear verification timer if user navigates away from verify stage
        return () => {
            clearInterval(verificationTimer);
        };
    }, [resendCountdown, stage]);

    return (
        <div>
            {stage === 'signup' && (
                <form onSubmit={handleSubmit}>
                    <h1>Signup</h1>
                    <label htmlFor="email">Email:</label>
                    <input type="email" id="email" name="email" value={userData.email} onChange={handleChange} required />
                    <label htmlFor="password">Password:</label>
                    <input type="password" id="password" name="password" value={userData.password} onChange={handleChange} required />
                    <label htmlFor="username">Username:</label>
                    <input type="text" id="username" name="username" value={userData.username} onChange={handleChange} required />
                    <button type="submit" disabled={isLoading}>
                        {isLoading ? 'Loading...' : 'Signup'}
                    </button>
                    {errorMessage && <p className="error-message">{errorMessage}</p>}

                    <p>Already have an account? <Link to="/login">Login</Link></p>
                </form>
            )}
            {stage === 'verify' && (
                <div>
                    <h1>Verify OTP</h1>
                    <p>A verification code has been sent to your email address.</p>
                    <label htmlFor="otp">OTP:</label>
                    <input type="text" id="otp" value={otp} onChange={(e) => setOtp(e.target.value)} required />
                    <button type="submit" onClick={handleSubmit} disabled={isLoading}>
                        {isLoading ? 'Loading...' : 'Verify'}
                    </button>
                    <button type="button" onClick={handleResendOtp} disabled={resendDisabled}>
                        {resendDisabled ? `Resend OTP in ${resendCountdown} seconds` : 'Resend OTP'}
                    </button>
                    {errorMessage && <p className="error-message">{errorMessage}</p>}
                    {successMessage && <p className="success-message">{successMessage}</p>}
                    {resendCountdown > 0 && <p>Time remaining: {resendCountdown} seconds</p>}
                </div>
            )}
        </div>
    );
}

export default Signup;
