export type IsUnion<T> = helper2<T> extends helper1<T> ? false : true;
type helper1<T> = T extends any ? T[] : never;
type helper2<T> = [T] extends [any] ? T[] : never;

type aDist = helper1<1 | 2 | 3>;
type a = helper2<1 | 2 | 3>;

type _ = 1[] | 2[] extends (1 | 2)[] ? true : false;
// TODO checkout did Union distribute happens here?
type __ = (1 | 2)[] extends 1[] | 2[] ? true : false;

type bDist = helper1<1>;
type b = helper2<1>;

type isUnion1 = IsUnion<1 | 2 | 3>;
type isUnion2 = IsUnion<1>;
