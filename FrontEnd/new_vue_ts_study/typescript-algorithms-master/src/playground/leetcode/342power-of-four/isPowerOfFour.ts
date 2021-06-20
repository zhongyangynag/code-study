//   0 1 0 1 0 1 0 1
//    64  16   4   1
// -----------------
//   1 0 0 0 0 0 0 0
//   0 1 1 1 1 1 1 1
// &----------------
//   0 0 0 0 0 0 0 0
export default function isPowerOfFour(num: number): boolean {
    return (
        num > 0 && // is positive.
        (num & (num - 1)) === 0 && // is power of 2.
        (num & 0x55555555) === num // is power of 4.
    );
    /** 
        return (
            (num > 0 && 
            (num ^ 0x1) === 0) ||
            (num ^ 0x4) === 0 ||
            (num ^ 0x10) === 0 ||
            (num ^ 0x40) === 0 ||
            (num ^ 0x100) === 0 ||
            (num ^ 0x400) === 0 ||
            (num ^ 0x1000) === 0 ||
            (num ^ 0x4000) === 0 ||
            (num ^ 0x10000) === 0 ||
            (num ^ 0x40000) === 0 ||
            (num ^ 0x100000) === 0 ||
            (num ^ 0x400000) === 0 ||
            (num ^ 0x1000000) === 0 ||
            (num ^ 0x4000000) === 0 ||
            (num ^ 0x10000000) === 0 ||
            (num ^ 0x40000000) === 0
        );
    */
}
