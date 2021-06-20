// import { IsUnion } from '../middle/IsUnion';
export type Union2Intersection<T> = helper<T, T>;

type helper<T, U> = T extends U
    ? T & (Exclude<U, T> extends never ? T : Union2Intersection<Exclude<U, T>>)
    : T;

// type T<T, U> = Exclude<U, T>;
// type t = IsUnion<T<'a', 'a' | 'b' | 'c'>>;

// type I = Union2Intersection<'foo' | 42 | true>; // expected to be 'foo' & 42 & true

// type Bar<T> = T extends { a: (x: infer U) => void; b: (x: infer U) => void }
//     ? U
//     : never;

// type T21 = Bar<{
//     a: (x: { name: string }) => void;
//     b: (x: { num: number }) => void;
// }>; // T1 & T2

// type Foo<T> = T extends [(x: infer U) => void, (x: infer U) => void]
//     ? U
//     : never;

// type T22 = Foo<[(x: { name: string }) => void, (x: { num: number }) => void]>; // T1 & T2

// type UnionToIntersection<T> = (T extends any ? (x: T) => void : never) extends (
//     x: infer U
// ) => void
//     ? U
//     : never;

type UnionToIntersection<U> = (U extends any ? (k: U) => void : never) extends (
    k: infer I
) => void
    ? I
    : never;

// type Result = UnionToIntersection<string | number>; // T1 & T2

type T1 = { name: string };
type T2 = { age: number };

// // ((k: "b") => void) | ((k: "a") => void)

type Result = Union2Intersection<T1 | T2>; // T1 & T2

type nvr = string & number;
