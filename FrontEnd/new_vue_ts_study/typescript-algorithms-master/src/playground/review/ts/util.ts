// 构造一个所有属性都Type设置为optional的类型。
type MyPartial<T> = {
    [K in keyof T]+?: T[K];
};

// 构造一个类型，该类型由Typeset的所有属性设置为required。
type MyRequiredl<T> = {
    [K in keyof T]-?: T[K];
};

// 构造一个所有属性都Type设置为的类型readonly，这意味着无法重新分配所构造类型的属性。
type MyReadOnly<T> = {
    +readonly [K in keyof T]: T[K];
};

// 构造一个所有属性都Type设置为的类型readable。
type MyReadable<T> = {
    -readonly [K in keyof T]: T[K];
};

//  TODO 构造一个对象类型，其属性键为Keys，属性值为Type。
type MyRecord<K extends string, T> = {
    [k in K]: T;
};
type xxx = Record
// 通过从Type可分配给的所有联合成员中提取来构造类型Union。
type MyInclude<T, U> = T extends U ? T : never;

// 通过从Type可分配给的所有联合成员中排除来构造类型ExcludedUnion。
type MyExclude<T, U> = T extends U ? never : T;

// 通过Keys从中选择属性集来构造类型Type。
type MyPick<T, U> = {
    [K in MyInclude<keyof T, U>]: T[K];
};

// 通过从中选择所有属性Type然后删除来构造一个类型Keys。
type MyOmit<T, U> = {
    [K in MyExclude<keyof T, U>]: T[K];
};

// Constructs a type by excluding null and undefined from Type.
type MyNonNullable<T> = MyExclude<T, null | undefined>;

type MyReturnType<T> = T extends (...args: never[]) => infer Return
    ? Return
    : never;

// type returnType = MyReturnType<() => string>;

let func: (...args: never[]) => void;
// let func: (...args: unknown[]) => void;
func = (leo: string) => {
    return new Date();
};

// type returnType = MyReturnType<string>;

function myForEach(
    arr: any[],
    callback: (arg: any, index: /* ? */ number) => void
) {
    // console.log(index);
    for (let i = 0; i < arr.length; i++) {
        callback(arr[i], i);
    }
}
myForEach([1, 2, 3], (a) => console.log(a));

function vn(): never {
    while (true) {}
}

function fn(x: string | number) {
    if (typeof x === 'string') {
        // do something
    } else if (typeof x === 'number') {
        // do something else
    } else {
        x; // has type 'never'!
    }
}

type Person = {
    name: string;
    age?: number;
};

let obj: Man = {
    name: '',
};

obj.age = 1;

obj['age'];

let broProto = {
    funk() {
        return {};
    },
};

Object.setPrototypeOf(obj, broProto);

function manFunk(m: Man) {
    m.funk();
}

console.log(bro);
console.log(Object.getPrototypeOf(bro));
console.log(Bro.prototype);
console.log(obj);
console.log(Object.getPrototypeOf(obj));
// manFunk(bro)

// manFunk(obj);
type broKeys = keyof Bro;

let bb = bro['name' as string];
let bbb = bro['das'];
for (let key in bro) {
    console.log(bro[key]);
    console.log(bro[key as keyof Bro]);
}

obj?.name;

let arr = [1, 2, null, new Date(), Bro];

for (let v of arr) {
    console.log(v);
}

for (let k in arr) {
    console.log(arr[k]);
}
function a(b) {}

arr.forEach((item) => {
    console.log(item);
});

function padLeft(padding: number | string, input: string) {
    return new Array(padding + 1).join(' ') + input;
    // Operator '+' cannot be applied to types 'string | number' and 'number'.
}

function printAll(strs: string | string[] | null) {
    if (typeof strs === 'object') {
        for (const s of strs) {
            // Object is possibly 'null'.
            console.log(s);
        }
    } else if (typeof strs === 'string') {
        console.log(strs);
    } else {
        // do nothing
    }
}
let x = Math.random() < 0.5 ? 10 : 'hello world!';
let y = 1 < 0.5 ? 10 : 'hello world!';
let z = true ? 10 : 'hello world!';

let sym: Symbol = Symbol('b');

for (let s of sym.) {
    con;
}

let xxxxxx: unknown;
let l: number;
l = xxxxxx;