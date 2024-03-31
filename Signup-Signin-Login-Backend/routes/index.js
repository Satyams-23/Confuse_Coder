const express = require('express');
const mongoose = require('mongoose');

const router = express.Router();

const moduleRoutes = [
    {
        path: '/auth',
        module: require('./authRoutes')


    },
    {
        path: '/patient',
        module: require('./patientRoutes')
    },
    {
        path: '/doctor',
        module: require('./doctorRoutes')
    }
]
    ;

moduleRoutes.forEach(route => {
    router.use(route.path, route.module);
}

);

module.exports = router;