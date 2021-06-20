// // interface dictory {
// //     [propName: string]: string;
// //     [propName: number]: string;
// // }

// // interface IDictoryArray {
// //     [propName: number]: string;
// //     length: number;
// //     name: number;
// //     age: object;
// // }

// // interface IArray {
// //     [propName: string]: number;
// //     length: string;
// // }

// // interface IMan {
// //     name: string;
// // }

// // class Man {
// //     name: string;
// //     constructor(name: string) {
// //         this.name = name;
// //     }
// // }

// // let m: IMan = new Man('');

// // // class Greeter {
// // //     greeting: string;
// // //     constructor(message: string) {
// // //         this.greeting = message;
// // //     }
// // //     greet() {
// // //         return 'Hello, ' + this.greeting;
// // //     }
// // // }

// // interface Greeter {
// //     greeting: string;
// //     greet: (this: Greeter, word: string) => void;
// // }

// // let greeter: Greeter = {
// //     greeting: 'name',
// //     greet(this: Greeter, word: string) {
// //         return function () {
// //             console.log(this.greeting);
// //         };
// //     },
// // };

// // greeter.greet('zsh');

// // // let manMaker: typeof Man = Man;
// // // let man: Man = new manMaker(''); // ok

// // // let manMaker: Man = Man;
// // // let man: Man = new manMaker(''); // not ok

// // type handler = () => void;
// // let func: handler = () => {};

// // enum EventType {
// //     Mouse,
// //     Keyboard,
// // }

// // interface Events {}
// // interface MouseEvents extends Events {
// //     // x: number;
// //     // y: number;
// // }
// // interface KeyEvents extends Events {
// //     keyCode: number;
// // }

// // function listenEvents(events: Array<Events>) {
// //     events.push({} as KeyEvents);
// // }

// // let mouseEvent: MouseEvents = {};

// // listenEvents([mouseEvent] as Array<MouseEvents>);

// class Man {
//     name: string;
//     constructor(name: string) {
//         this.name = name;
//     }
//     funk() {
//         console.log('funk');
//     }
// }

// interface IMan {
//     name: string;
//     funk: () => void;
//     [propName: string]: any; // ??
// }

// let man: IMan = new Man('');

// console.log(man);

// for (let key in man) {
//     console.log(man[key]);
// }

// let x = [0, 1, null];
// console.log(typeof x);

// function extend<T extends object, U extends object>(
//     first: T,
//     second: U
// ): T & U {
//     let result = <T & U>{};
//     for (let id in first) {
//         // result[id] = first[id];
//     }
//     for (let id in second) {
//         if (!result.hasOwnProperty(id)) {
//             (<any>result)[id] = (<any>second)[id];
//         }
//     }
//     return result;
// }

// let a = 1;
// type t = keyof string;
// type tt = keyof String;

// type Flatten<T> = T extends any[] ? T[number] : T;
// let arr = [1, '2', []];

// type arrType = Flatten<typeof arr>;

// interface Student {
//     name: string;
//     id: number;
// }

// interface Human {
//     name: string;
// }
// function nullR(): void {
//     return undefined;
// }

// let tunple: [string, number] = ['', 1];

// // type Include<T, U> = T extends U ? T : never;

// // type MyPick<T, U> = {
// //     [K in Include<keyof T, keyof U>]: T[K];
// // };

// // type MyPick<T, U> = {
// //     [K in T extends keyof U ? keyof T : never]: T[K];
// // };

// // type MyExclude<T, U> = T extends U ? never : T;

// type MyKicp<T, U> = {
//     [K in MyExclude<keyof T, keyof U>]: T[K];
// };

// type HumanStudent = MyPick<Student, Human>;

// type StudentHuman = MyKicp<Student, Human>;

