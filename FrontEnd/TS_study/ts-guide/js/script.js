"use strict";
var myName; // String
myName = "Harry Manchanda";
console.log(myName);
var myAge; // Number
myAge = 25;
console.log(myAge);
var hasHobbies; // Boolean
hasHobbies = true;
console.log(hasHobbies);
var hobbies; // Array of Strings
hobbies = ["Cooking", "Sports"];
console.log(hobbies);
var marks; // Array of Numbers
marks = [92, 81, 75];
console.log(marks);
var address; // Tuple (For Array)
address = ["C-3 Janakpuri", 182];
console.log(address);
// enum
var Color;
(function (Color) {
    Color[Color["Gray"] = 0] = "Gray";
    Color[Color["Green"] = 100] = "Green";
    Color[Color["Blue"] = 2] = "Blue";
    Color[Color["Red"] = 3] = "Red";
})(Color || (Color = {}));
var grayColor = Color.Gray;
var greenColor = Color.Green;
var blueColor = Color.Blue;
var redColor = Color.Red;
console.log(grayColor, greenColor, blueColor, redColor);
// Functions
var returnMyName = function () {
    return myName;
};
console.log(returnMyName());
var sayHello = function () {
    console.log('Hello World');
};
sayHello();
var multiply = function (value1, value2) {
    return value1 * value2;
};
console.log(multiply(2, 3));
var myMultiply; // Function Types
myMultiply = multiply;
console.log(myMultiply(2, 3));
// Object Types
var userData;
userData = {
    name: 'Harry',
    age: 25,
};
console.log(userData);
var complexObject = {
    data: [100, 3.99, 10],
    output: function (all) {
        if (all) {
            return this.data;
        }
        else {
            return [NaN];
        }
    }
};
console.log(complexObject.output(false));
console.log(complexObject.output(true));
// Union Types
var myRealAge;
myRealAge = 24;
console.log(myRealAge);
myRealAge = '24';
console.log(myRealAge);
// Never Type
/*
const neverReturnsThrowsError = (): never => {
  throw new Error('An Error');
};
neverReturnsThrowsError();
*/
// Nullable Types
var canBeNull;
canBeNull = 12;
console.log(canBeNull);
canBeNull = null;
console.log(canBeNull);
var canThisBeAny = null;
console.log(canThisBeAny);
canThisBeAny = 12;
console.log(canThisBeAny);
//# sourceMappingURL=script.js.map