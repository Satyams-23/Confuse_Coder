const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
require('dotenv').config();
const session = require('express-session');
// ssession middleware
const authRoutes = require('./routes/authRoutes');
const { deleteUnverifiedUsers } = require('./middleware/auth');


const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: true })); // Parse URL-encoded bodies 


app.use(express.json());
app.use(cors({ origin: 'http://localhost:3000', credentials: true }));





const PORT = process.env.PORT || 5000;

app.use(deleteUnverifiedUsers);




app.use('/api/v1', authRoutes);

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



