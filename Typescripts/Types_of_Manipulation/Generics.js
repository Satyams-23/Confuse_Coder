"use strict";
const profile = (obj) => {
    let RollNo = Math.floor(Math.random() * 100);
    return Object.assign(Object.assign({}, obj), { RollNo });
};
let obj = {
    name: "John",
};
