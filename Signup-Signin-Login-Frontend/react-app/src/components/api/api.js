// api.js

// Function to make a POST request to the signup endpoint
export const signup = async (userData) => {
    try {
        const response = await fetch('/api/signup', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(userData),
        });
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error signing up:', error);
        throw error;
    }
};

// Function to make a POST request to the verify OTP endpoint
export const verifyOTP = async (otpData) => {
    try {
        const response = await fetch('/api/verify-otp', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(otpData),
        });
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error verifying OTP:', error);
        throw error;
    }
};

// Function to make a POST request to the resend OTP endpoint
export const resendOTP = async () => {
    try {
        const response = await fetch('/api/resend-otp', {
            method: 'POST',
        });
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error resending OTP:', error);
        throw error;
    }
};
