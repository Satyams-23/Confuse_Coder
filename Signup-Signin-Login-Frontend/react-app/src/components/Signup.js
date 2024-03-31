import React, { useState } from 'react';
import { Link, useNavigate } from 'react-router-dom'; // Import the useNavigate hook from 'react-router-dom'
import './Signup.css'; // Import your CSS file for styling

const Signup = () => {
    // State variables to store form data
    const [username, setUsername] = useState('');
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const Navigate = useNavigate();

    // Function to handle form submission
    const handleSubmit = async (e) => {
        await e.preventDefault();
        // Perform signup logic here
        console.log('Form submitted:', { username, email, password });
        // Reset form fields after submission
        setUsername('');
        setEmail('');
        setPassword('');

        // Redirect to OTP verification page
        Navigate('/otp-verification');
    }



    return (
        <div className="signup-container">
            <h2>Sign Up</h2>
            <form onSubmit={handleSubmit}>
                <div className="form-group">
                    <label htmlFor="username">Username</label>
                    <input
                        type="text"
                        id="username"
                        value={username}
                        onChange={(e) => setUsername(e.target.value)}
                        required
                    />
                </div>
                <div className="form-group">
                    <label htmlFor="email">Email</label>
                    <input
                        type="email"

                        id="email"
                        value={email}
                        onChange={(e) => setEmail(e.target.value)}
                        required
                    />
                </div>
                <div className="form-group">
                    <label htmlFor="password">Password</label>
                    <input
                        type="password"
                        id="password"
                        value={password}
                        onChange={(e) => setPassword(e.target.value)}
                        required
                    />
                </div>
                <button type="submit">Sign Up</button>

                {/* //link to signin  */}


                <p className="signin">Already have an account? <Link to="/signin">Sign In</Link></p>



            </form>
        </div>
    );
}



export default Signup;
