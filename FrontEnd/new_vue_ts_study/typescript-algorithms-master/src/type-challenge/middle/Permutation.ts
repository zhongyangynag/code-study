type Permutation<T> = helper<T, T>;
type helper<T, U> = T extends U
    ? [T, ...(Exclude<U, T> extends never ? [] : Permutation<Exclude<U, T>>)]
    : [];

type perm = Permutation<'A' | 'B' | 'C'>;
// ['A', 'B', 'C'] | ['A', 'C', 'B'] | ['B', 'A', 'C'] | ['B', 'C', 'A'] | ['C', 'A', 'B'] | ['C', 'B', 'A']
