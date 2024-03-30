const nodemailer = require('nodemailer');
const dotenv = require('dotenv');
const path = require('path');

const generateOTP = require('./generateOTP');

dotenv.config({ path: path.join(__dirname, '../.env') });
dotenv.config();


const
    sendEmail = async (to, subject, text) => {
        try {
            const transporter = nodemailer.createTransport({
                host: process.env.SMTP_HOST,
                port: process.env.SMTP_PORT,
                secure: false,
                requireTLS: true,
                auth: {
                    user: process.env.EMAIL_ADDRESS,
                    pass: process.env.EMAIL_PASSWORD,
                },
                tls: {
                    ciphers: "SSLv3",
                    rejectUnauthorized: false, // Set to false to ignore self-signed certificate issues
                },
            });


            const mailOptions = {
                from: process.env.EMAIL_ADDRESS,
                to: to || "",
                subject: subject,
                text: text,
            };

            await transporter.sendMail(mailOptions);

        } catch (error) {
            console.error('Error sending email:', error);
        }
    }

module.exports = sendEmail;