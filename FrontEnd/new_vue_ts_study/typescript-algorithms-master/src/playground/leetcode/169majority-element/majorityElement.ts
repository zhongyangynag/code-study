function majorityElement(nums: number[]): number[] {
    const n = nums.length;
    const range = Math.floor(n / 2);
    const store = new Map();
    const res: Set<number> = new Set();
    for (let i = 0; i < n; i++) {
        let curr = nums[i];
        if (!store.has(curr)) store.set(curr, 0);
        let count = store.get(curr);
        if (count >= range) res.add(curr);
        store.set(curr, count + 1);
    }

    return [...res];
}
