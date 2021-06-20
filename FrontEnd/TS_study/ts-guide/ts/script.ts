let myName: string; // String
myName = "Harry Manchanda";
console.log(myName);

let myAge: number; // Number
myAge = 25;
console.log(myAge);

let hasHobbies: boolean; // Boolean
hasHobbies = true;
console.log(hasHobbies);

let hobbies: string[]; // Array of Strings
hobbies = ["Cooking", "Sports"];
console.log(hobbies);

let marks: number[]; // Array of Numbers
marks = [92, 81, 75];
console.log(marks);

let address: [string, number]; // Tuple (For Array)
address = ["C-3 Janakpuri", 182];
console.log(address);

// enum
enum Color {
  Gray,
  Green = 100,
  Blue = 2,
  Red
}

let grayColor: Color = Color.Gray;
let greenColor: Color = Color.Green;
let blueColor: Color = Color.Blue;
let redColor: Color = Color.Red;
console.log(grayColor, greenColor, blueColor, redColor);

// Functions
const returnMyName = (): string => { // Return a String
  return myName;
};
console.log( returnMyName() );

const sayHello = (): void => { // Void (Not allowed to return anythings)
  console.log('Hello World');
};
sayHello();

const multiply = (value1: number, value2: number): number => { // Argument Types
  return value1 * value2;
};
console.log( multiply(2, 3) );

let myMultiply: (value1: number, value2: number) => number; // Function Types
myMultiply = multiply;
console.log( myMultiply(2, 3) );

// Object Types
let userData: { // Type Definitions for Key Value Pairs of an Object
  name: string,
  age: number,
};
userData = { // Key Value Pairs of an Object
  name: 'Harry',
  age: 25,
};
console.log( userData );

// Custom Types - Type Alias
type Complex = {
  data: number[],
  output: (all: boolean) => number[]
};

const complexObject: Complex = {
  data: [100, 3.99, 10],
  output(all) {
    if (all) { return this.data; }
    else { return [NaN]; }
  }
};
console.log( complexObject.output(false) );
console.log( complexObject.output(true) );

// Union Types
let myRealAge: number | string;
myRealAge = 24;
console.log( myRealAge );
myRealAge = '24';
console.log( myRealAge );

// Never Type
/* 
const neverReturnsThrowsError = (): never => {
  throw new Error('An Error');
};
neverReturnsThrowsError(); 
*/

// Nullable Types
let canBeNull: number | null;
canBeNull = 12;
console.log( canBeNull );
canBeNull = null;
console.log( canBeNull );

let canThisBeAny = null;
console.log( canThisBeAny );
canThisBeAny = 12;
console.log( canThisBeAny );
