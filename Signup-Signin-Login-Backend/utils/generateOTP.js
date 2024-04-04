//generate OTP

const generateOTP = async (req, res, next) => {
    const otp = Math.floor(10000 + Math.random() * 60000);// 

    return otp;
}

module.exports = generateOTP;