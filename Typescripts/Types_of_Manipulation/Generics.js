"use strict";
const profile = (obj) => {
    let RollNo = Math.floor(Math.random() * 100);
    return Object.assign(Object.assign({}, obj), { RollNo });
};
let obj = profile({
    name: "John",
});
console.log(obj.name);
const profile2 = {
    name: "John",
    RollNo: 1,
    data: { name: "John" },
};
const profile3 = {
    name: "John",
    RollNo: 1,
    data: ["John", "Doe"],
};
