// majority - element - ii;
// 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

export default function majorityElement(nums: number[]): number[] {
    const n = nums.length;
    const range = Math.floor(n / 3);
    const store: Map<number, number> = new Map();
    const res: Set<number> = new Set();
    for (let i = 0; i < n; i++) {
        let curr = nums[i];
        if (!store.has(curr)) {
            store.set(curr, 0);
            break;
        }
        let count = store.get(curr) as number;
        if (count >= range) res.add(curr);
        store.set(curr, count + 1);
    }
    return [...res];
}

console.log(majorityElement([1, 1, 1, 3, 3, 2, 2, 2]));
