import express from 'express';
import fetch from 'node-fetch';
import bodyParser from 'body-parser';
import cors from 'cors';

const app = express();
app.use(cors());
app.use(bodyParser.json());

const CLIENT_ID = 'YOUR_CLIENT_ID';
const CLIENT_SECRET = 'YOUR_CLIENT_SECRET';

app.post('/get-token', async (req, res) => {
    try {
        const response = await fetch('https://outpost.mapmyindia.com/api/security/v2.0.0/oauth/token', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: new URLSearchParams({
                'grant_type': 'client_credentials',
                'client_id': '96dHZVzsAus7ScBAW1B5QeVFMMpAgiqEOS78ZR8d7jsrY7W5KuBnWep_iK2vMjnNhvx_c1VYNpWIsBWBIhujSQ==',
                'client_secret': 'lrFxI-iSEg-ou-BZCSM4KaK0BNRN-qmhcZ-cuV33IC1-ApVjQ2iX2snQ1Hlw8EI5nCFozbipIvu5lg7XF2SKo9nNznP1OeGd'
            })
        });
        const data = await response.json();
        if (response.ok) {
            res.json(data);
        } else {
            res.status(response.status).json(data);
        }
    } catch (error) {
        res.status(500).json({ error: 'Failed to fetch token' });
    }
});


const PORT = process.env.PORT || 3001;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
