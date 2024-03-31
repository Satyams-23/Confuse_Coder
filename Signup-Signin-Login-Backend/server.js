const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
require('dotenv').config();
const session = require('express-session');
const routes = require('./routes/index');
// ssession middleware

const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: true })); //
app.use(cookieparser());


app.use(
    session({
        secret: config.session_secret, // Generate a new secret key on server restart
        resave: false,
        saveUninitialized: true,
        cookie: {
            secure: false, // Set to true if your app is served over HTTPS
            // maxAge: 1000 * 60 * 5,
            httpOnly: true,
        },
    }),
);

const PORT = process.env.PORT;


app.use('/api/v1', routes);

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



