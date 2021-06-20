//TODO 尝试递归解法，失败，需要能将元组转化为数组的方法，可惜。
// type Last<T extends any[]> = T[1] extends never ? T[0] : Last<Array<Exclude<T[number], T[0]>>>;
//!pass
export type Last<T extends any> = T extends [...infer _, infer L] ? L : never;
export type LastInterestingVersion<
    T extends any[],
    U extends never[] = [never]
> = [...U, ...T][T['length']];

type arr1 = ['a', 'b', 'c'];
type arr2 = [3, 2, 1];

type tail1 = Last<arr1>; // expected to be 'c'
type tail2 = Last<arr2>; // expected to be 1
