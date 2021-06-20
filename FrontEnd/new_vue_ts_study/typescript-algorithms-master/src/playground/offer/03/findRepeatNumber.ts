export default function findRepeatNumber(nums: number[]): number {
    const s = new Set();
    for (let num of nums) {
        if (s.has(num)) {
            return num
        }
        s.add(num)
    }
    return -1
};