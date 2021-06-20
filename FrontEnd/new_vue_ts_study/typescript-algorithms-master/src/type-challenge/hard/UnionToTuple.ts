export type Union2Tuple<T> = helper<T, T>;

type helper<T, U> = T extends U
    ? [T, ...(Exclude<U, T> extends never ? [] : Union2Tuple<Exclude<U, T>>)]
    : [];

type t = Union2Tuple<'any' | 'a'>; // ['a','any'], and correct
