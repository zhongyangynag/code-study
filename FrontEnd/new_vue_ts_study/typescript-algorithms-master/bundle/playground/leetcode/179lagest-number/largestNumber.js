"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function largestNumber(nums) {
    nums.sort(sortCallbackPro);
    return nums[0] ? nums.join("") : "0";
}
exports.default = largestNumber;
function sortCallbackPro(a, b) {
    var S1 = "" + a + b;
    var S2 = "" + b + a;
    return Number(S2) - Number(S1);
}
function sortCallback(a, b) {
    if (a === b) {
        return 0;
    }
    var strA = a.toString();
    var strB = b.toString();
    var range = Math.min(strA.length, strB.length);
    for (var i = 0; i < range; i++) {
        var curA = Number(strA[i]);
        var curB = Number(strB[i]);
        if (curA > curB) {
            return -1;
        }
        else if (curA < curB) {
            return 1;
        }
    }
    if (strA.length > strB.length) {
        return Number(strA[range]) > Number(strB[0]) ? -1 : 1;
    }
    else {
        return Number(strB[range]) > Number(strA[0]) ? 1 : -1;
    }
}
//# sourceMappingURL=largestNumber.js.map