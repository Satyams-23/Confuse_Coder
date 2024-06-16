import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import './Signup.css'; // Import CSS file for styling
import axios from 'axios'; // Assuming using axios for API calls

const Login = () => {
    const [userData, setuserData] = useState({
        email: '',
        password: '',
    });
    const [errorMessage, setErrorMessage] = useState(null);
    const [isLoading, setIsLoading] = useState(false);

    const handleChange = (e) => {
        setuserData({ ...userData, [e.target.name]: e.target.value });
    }

    const handleSubmit = async (e) => {
        e.preventDefault();
        setIsLoading(true);
        setErrorMessage(null);

        try {
            const response = await axios.post('http://localhost:5000/api/v1/signin', userData);
            console.log('Login response:', response.data);
            setErrorMessage('Login successful');
        } catch (error) {
            setErrorMessage(error.response?.data?.message || 'Login failed');
        } finally {
            setIsLoading(false);
        }
    }

    return (
        <div className="login-container">
            <h2>Login</h2>
            <form onSubmit={handleSubmit}>
                <div className="form-group">
                    <label>Email</label>
                    <input type="email" name="email" value={userData.email} onChange={handleChange} required />
                </div>
                <div className="form-group">
                    <label>Password</label>
                    <input type="password" name="password" value={userData.password} onChange={handleChange} required />
                </div>
                <button type="submit" disabled={isLoading}>{isLoading ? 'Loading...' : 'Login'}</button>
                {errorMessage && <div className="error-message">{errorMessage}</div>}

                <p>Don't have an account? <Link to="/">Signup</Link></p>
                <p>Forgot password? <Link to="/forgot-password">Reset password</Link></p>


            </form>
        </div>
    );
}

export default Login;
