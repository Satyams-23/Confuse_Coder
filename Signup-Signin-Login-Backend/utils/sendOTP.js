const twilio = require('twilio');
const dotenv = require('dotenv');

dotenv.config();

const accountSid = process.env.TWILIO_ACCOUNT_SID;
const authToken = process.env.TWILIO_AUTH_TOKEN;

const client = new twilio(accountSid, authToken);

const sendOTP = async (to, subject, text) => {
    try {
        await client.messages.create({
            body: text,
            from: process.env.TWILIO_PHONE_NUMBER,
            to,
        });
    } catch (error) {
        console.error('Error sending OTP:', error);
    }


}

module.exports = sendOTP;