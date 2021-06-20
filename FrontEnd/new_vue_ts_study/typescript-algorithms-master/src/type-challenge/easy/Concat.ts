//!pass
type Concat<T extends any[], U extends any[]> = [...T, ...U];
// TODO what is this fucking grammer?
type Result = Concat<[1], [2]>;
// expected to be [1, 2]
