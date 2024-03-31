import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Signup from './components/Signup';
import OTPVerification from './components/otpVerification';

function App() {
  return (
    <Router>
      <div className="App">
        <Routes>
          <Route path="/" element={<Signup />} />
          <Route path="/otp-verification" element={<OTPVerification />} />
        </Routes>
      </div>
    </Router>
  );
}

export default App;
