export type Merge<T, U> = {
    [K in keyof T | keyof U]: K extends keyof U
        ? U[K]
        : K extends keyof T
        ? T[K]
        : never;
};

type A = {
    a: string;
};

type B = {
    b: string;
};

type AB = {
    a: number;
    b: string;
};

type AB2 = Merge<A, B>;

type AB3 = Merge<A, AB>;

let a: never = (function () {
    throw new Error('Not Implemented');
})();

let b: number = a;
