export type IsNever<T> = [T] extends [never] ? true : false;
type isNever = never extends never ? true : false;
// only happends in distribute
type A = IsNever<never>; // expected to be true
type C = IsNever<null>; // expected to be false
type D = IsNever<[]>; // expected to be false
type E = IsNever<number>; // expected to be false
