export type AnyOf<T extends readonly any[]> = T extends readonly [
    infer F,
    ...infer R
]
    ? Or<ToBoolean<F>, AnyOf<R>>
    : false;

type Or<T, U> = [T, U] extends [false, false] ? false : true;

type ToBoolean<T> = T extends ''
    ? false
    : T extends 0
    ? false
    : T extends 0n
    ? false
    : T extends null
    ? false
    : T extends undefined
    ? false
    : T extends false
    ? false
    : T extends readonly []
    ? false
    : T extends object
    ? keyof T extends never
        ? false
        : true
    : true;

type Sample1 = AnyOf<[1, '', false, [], {}]>; // expected to be true.
type Sample2 = AnyOf<[0, '', false, [], {}]>; // expected to be false.
