//!pass
export type Include<T, U> = T extends U ? T : never;
export type First<T extends any[]> = Include<T[number], T[0]>;

type arr1 = ['a', 'b', 'c'];
type arr2 = [3, 2, 1];

type head1 = First<arr1>; // expected to be 'a'
type head2 = First<arr2>; // expected to be 3

type ddd = Include<'aaa' | 'bbb', 'ccc'>;
