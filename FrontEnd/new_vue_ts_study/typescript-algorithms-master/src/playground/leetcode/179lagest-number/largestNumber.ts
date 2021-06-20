export default function largestNumber(nums: number[]): string {
    // nums.sort(sortCallback);
    nums.sort(sortCallbackPro);
    return nums[0] ? nums.join("") : "0";
}

function sortCallbackPro(a: number, b: number): number {
    let S1 = `${a}${b}`;
    let S2 = `${b}${a}`;
    return Number(S2) - Number(S1);
}

function sortCallback(a: number, b: number): number {
    if (a === b) {
        return 0;
    }

    let strA = a.toString();
    let strB = b.toString();

    let range = Math.min(strA.length, strB.length);

    for (let i = 0; i < range; i++) {
        let curA = Number(strA[i]);
        let curB = Number(strB[i]);

        if (curA > curB) {
            return -1;
        } else if (curA < curB) {
            return 1;
        }
    }

    if (strA.length > strB.length) {
        return Number(strA[range]) > Number(strB[0]) ? -1 : 1;
    } else {
        return Number(strB[range]) > Number(strA[0]) ? 1 : -1;
    }
}
