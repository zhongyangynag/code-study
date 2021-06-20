export type Pop<T extends any[]> = T extends [...infer U, infer _] ? U : never;
export type Shift<T extends any[]> = T extends [infer _, ...infer U]
    ? U
    : never;
export type UnShift<T extends any[], N> = [N, ...T];
export type Push<T extends any[], N> = [...T, N];

type arr1 = ['a', 'b', 'c', 'd'];
type arr2 = [3, 2, 1];

type re1 = Pop<arr1>; // expected to be ['a', 'b', 'c']
type re2 = Push<arr1, 1>; // expected to be [3, 2]
type re3 = UnShift<arr1, 1>; // expected to be [3, 2]
type re4 = Shift<arr1>; // expected to be [3, 2]
