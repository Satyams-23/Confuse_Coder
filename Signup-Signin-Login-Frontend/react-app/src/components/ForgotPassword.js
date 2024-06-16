import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import './Signup.css'; // Import CSS file for styling
import axios from 'axios'; // Assuming using axios for API calls

const ForgotPassword = () => {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [confirmpassword, setonfirmpassword] = useState('');
    const [otp, setOtp] = useState('');
    const [stage, setStage] = useState('forgot-password');
    const [errorMessage, setErrorMessage] = useState(null);
    const [successMessage, setSuccessMessage] = useState(null);
    const [isLoading, setIsLoading] = useState(false);
    const [resendDisabled, setResendDisabled] = useState(false);
    const [resendCountdown, setResendCountdown] = useState(0);

    const handleChange = (e) => {
        const { name, value } = e.target;
        if (name === 'email') setEmail(value);
        if (name === 'password') setPassword(value);
        if (name === 'confirmpassword') setonfirmpassword(value);
        if (name === 'otp') setOtp(value);
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        setIsLoading(true);
        setErrorMessage(null);
        setSuccessMessage(null);

        try {
            if (stage === 'forgot-password') {
                const response = await axios.post('http://localhost:5000/api/v1/forgot-password', { email });
                console.log('Forgot password response:', response.data);
                setStage('reset-password');
                setSuccessMessage('Password reset link sent to email');
            } else if (stage === 'reset-password') {
                const response = await axios.post('http://localhost:5000/api/v1/reset-password', { email, password, confirmpassword, otp });
                console.log('Reset password response:', response.data);
                setSuccessMessage('Password reset successfully');
            }
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Failed operation');
        } finally {
            setIsLoading(false);
        }
    };

    const handleResendOtp = async () => {
        setIsLoading(true);
        setErrorMessage(null);
        setSuccessMessage(null);

        try {
            const response = await axios.post('http://localhost:5000/api/v1/forgot-password/resendotp', { email });
            console.log('Resend OTP response:', response.data);
            setSuccessMessage('New OTP sent successfully');
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Failed to resend OTP');
        } finally {
            setIsLoading(false);
        }
    };

    return (
        <div className="forgot-password-container">
            {stage === 'forgot-password' && (
                <div>
                    <h2>Forgot Password</h2>
                    <form onSubmit={handleSubmit}>
                        <div className="form-group">
                            <label>Email</label>
                            <input type="email" name="email" value={email} onChange={handleChange} required />
                        </div>
                        <button type="submit" disabled={isLoading}>{isLoading ? 'Loading...' : 'Reset Password'}</button>
                        {errorMessage && <div className="error-message">{errorMessage}</div>}
                        {successMessage && <div className="success-message">{successMessage}</div>}
                    </form>
                    <p>Remembered your password? <Link to="/login">Login</Link></p>
                </div>
            )}
            {stage === 'reset-password' && (
                <div>
                    <h2>Reset Password</h2>
                    <form onSubmit={handleSubmit}>
                        <div className="form-group">
                            <label>New Password</label>
                            <input type="password" name="password" value={password} onChange={handleChange} required />
                        </div>
                        <div className="form-group">
                            <label>Confirm Password</label>
                            <input type="password" name="confirmpassword" value={confirmpassword} onChange={handleChange} required />
                        </div>
                        <div className="form-group">
                            <label>OTP</label>
                            <input type="text" name="otp" value={otp} onChange={handleChange} required />
                        </div>
                        <button type="submit" disabled={isLoading}>{isLoading ? 'Loading...' : 'Reset Password'}</button>
                        {errorMessage && <div className="error-message">{errorMessage}</div>}
                        {successMessage && <div className="success-message">{successMessage}</div>}
                    </form>
                    <button type="button" onClick={handleResendOtp} disabled={isLoading || resendDisabled}>
                        {isLoading ? 'Loading...' : resendDisabled ? `Resend OTP in ${resendCountdown} seconds` : 'Resend OTP'}
                    </button>
                </div>
            )}
        </div>
    );
};

export default ForgotPassword;
