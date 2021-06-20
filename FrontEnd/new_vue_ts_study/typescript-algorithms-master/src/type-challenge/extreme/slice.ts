// type Slice<T extends any[], S, E> = T extends [infer F, ...infer R]
type Arr = [1, 2, 3, 4, 5];
// type Result = Slice<Arr, 2, 4>; // expected to be [3, 4]
