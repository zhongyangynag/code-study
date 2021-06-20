// export type DeepReadOnly<T> = {
//     +readonly [K in keyof T]: T[K] extends Object ? DeepReadOnly<T[K]> : T[K];
// };

type Primitive = number | string | boolean | null | undefined | symbol;
export type DeepReadonly<T> = {
    +readonly [P in keyof T]: T[P] extends Primitive
        ? T[P]
        : DeepReadonly<T[P]>;
};

type X = {
    x: {
        a: 1;
        b: 'hi';
    };
    y: 'hey';
};

type Expected = {
    readonly x: {
        readonly a: 1;
        readonly b: 'hi';
    };
    readonly y: 'hey';
};

type RRX = DeepReadonly<X>;

let obj: RRX = {
    x: {
        a: 1,
        b: 'hi',
    },
    y: 'hey',
};

obj.x = 1;
obj.y = 1;
obj.x.a = 1;
obj.x.b = 1;
