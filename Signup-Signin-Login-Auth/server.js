const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
require('dotenv').config();
const session = require('express-session');



const authRoutes = require('./routes/authRoutes');

// ssession middleware

const app = express();


app.use(session({
    secret: 'your_secret_key_here', // Change this to a random secret key
    resave: false,
    saveUninitialized: true

}));

const PORT = process.env.PORT || 5000;

app.use(express.json());//middleware to parse json data from request body 

app.use('/api/auth', authRoutes);

// app.get('/', (req, res) => {
//     res.send('Welcome to the server');
// }
// );

mongoose.connect(process.env.MONGO_URI, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
})
    .then(() => {
        app.listen(PORT, () => {
            console.log(`Server is running on port ${PORT}`);
        });
    })
    .catch(err => {
        console.log(err);
    });



