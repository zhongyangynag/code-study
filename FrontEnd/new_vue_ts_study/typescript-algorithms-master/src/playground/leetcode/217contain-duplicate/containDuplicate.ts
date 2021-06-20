function containsDuplicate(nums: number[]): boolean {
    const s = new Set();
    for (let num of nums) {
        if (s.has(num)) return true;
        s.add(num);
    }
    return false;
}

console.log(containsDuplicate([1, 2, 3, 4]));
