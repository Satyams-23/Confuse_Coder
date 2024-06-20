


function* generator() {
    yield 1;
    yield 2;
}

const gen = generator();
const sym = Symbol('unique');//

gen[sym] = function () {
    return this.next().value;//
};

console.log(gen[sym](), gen[sym](), gen[sym]());//





explain:
1. The generator function generator is defined with two yield statements.
    2. The gen object is created by calling the generator function.

3. A new symbol sym is created with the description 'unique'.
    4. The sym symbol is used as a property key to add a new method to the gen object.
    5. The new method is a generator function that returns the value of the next() method.

    6. The new method is called three times on the gen object, which returns the values 1, 2, and undefined.
    7. The values are logged to the console.



