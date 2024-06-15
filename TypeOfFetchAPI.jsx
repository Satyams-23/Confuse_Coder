// ------Code: Type of Fetch API----------

// Date: 03/18/21

// 1. AXIOS

// 2. FETCH API (async/await)

// 3. XMLHttpRequest


// --------------------------
// 1. Syntax and Ease of Use
// 2. Browser Support
// 3. Handling Errors
// 4. Interceptor
// 5. Cancellation
























// XMLHttpRequest

//code

const xhr = new XMLHttpRequest();
xhr.open('GET', 'https://example.com', true);
xhr.onload = function () {
    if (this.status === 200) {
        console.log(JSON.parse(this.responseText));
    }
    else {
        console.log('Error');
    }
}
xhr.send();










// AXIOS

//code

import axios from 'axios';

// const fetchData = axios.get('https://example.com')
    .then(response => {
        console.log(response.data);
    }
    )
    .catch(error => {
        console.log(error);
    }
    );







// FETCH API (async await)

//code

const fetchData = async () => {
    try {
        const response = await fetch('https://example.com')
        const data = await response.json();
        console.log(data);
    }
    catch (error) {
        console.log(error);
    }
}

fetchData();















