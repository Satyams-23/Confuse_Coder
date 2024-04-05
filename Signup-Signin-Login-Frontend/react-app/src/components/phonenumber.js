import React, { useState } from 'react';
import axios from 'axios';

const Phonenumber = () => {
    const [phoneNumber, setPhonenumber] = useState('');//phone number state variable to store phone number input value from user 
    const [errorMessage, setErrorMessage] = useState(null);
    const [isLoading, setIsLoading] = useState(false);
    const [otp, setOtp] = useState('');
    const [stage, setStage] = useState('phoneNumber');
    const [successMessage, setSuccessMessage] = useState(null);
    const [resendDisabled, setResendDisabled] = useState(false);
    const [resendCountdown, setResendCountdown] = useState(0);

    const handleChange = (e) => {
        const { name, value } = e.target;
        if (name === 'phoneNumber') setPhonenumber(value);//
        if (name === 'otp') setOtp(value);
    }

    const handleSubmit = async (e) => {
        e.preventDefault();
        setIsLoading(true);
        setErrorMessage(null);
        setSuccessMessage(null);

        try {
            if (stage === 'phoneNumber') {
                const response = await axios.post('http://localhost:5000/api/v1/register', { phoneNumber });
                console.log('Phonenumber response:', response.data);
                setStage('otp');
                setSuccessMessage('OTP sent to phone number');
            } else if (stage === 'otp') {
                const response = await axios.post('http://localhost:5000/api/v1/register/verify', { phoneNumber, otp });
                console.log('OTP response:', response.data);
                setSuccessMessage('Phone number login successfully');
            }
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Failed operation');
        } finally {
            setIsLoading(false);
        }
    }

    const handleResendOtp = async () => {
        setIsLoading(true);
        setErrorMessage(null);
        setSuccessMessage(null);

        try {
            const response = await axios.post('http://localhost:5000/api/v1/register/resendotp', { phoneNumber });
            console.log('Resend OTP response:', response.data);
            setSuccessMessage('New OTP sent successfully');
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Failed to resend OTP');
        } finally {
            setIsLoading(false);
        }
    }

    return (
        <div className="phonenumber-container">
            <h2>Phone Number</h2>
            <form onSubmit={handleSubmit}>
                <div className="form-group">
                    <label>Phone Number</label>
                    <input type="text" name="phoneNumber" value={phoneNumber} onChange={handleChange} required />
                </div>
                {stage === 'otp' && (
                    <div className="form-group">
                        <label>OTP</label>
                        <input type="text" name="otp" value={otp} onChange={handleChange} required />
                    </div>
                )}
                <button type="submit" disabled={isLoading}>{isLoading ? 'Loading...' : 'Submit'}</button>
                {errorMessage && <div className="error-message">{errorMessage}</div>}
                {successMessage && <div className="success-message">{successMessage}</div>}
                {stage === 'otp' && (
                    <button type="button" onClick={handleResendOtp} disabled={resendDisabled}>
                        {resendDisabled ? `Resend OTP in ${resendCountdown} seconds` : 'Resend OTP'}
                    </button>
                )}
            </form>
        </div>
    );
}

export default Phonenumber;
