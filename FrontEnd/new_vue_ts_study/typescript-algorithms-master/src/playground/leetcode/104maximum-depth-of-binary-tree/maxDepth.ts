// import TreeNode from "../../../utils/leetcode/TreeNode.ts";
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

export default function maxDepth(root: TreeNode | null): number {
    return !root
        ? 0
        : Math.max(maxDepth(root.left) + 1, maxDepth(root.right) + 1);
}

function breakfastNumber(
    staple: number[],
    drinks: number[],
    x: number
): number {
    let m = staple.length;
    let n = drinks.length;
    let count = 0;
    staple.sort((a, b) => {
        return a - b;
    });
    drinks.sort((a, b) => {
        return a - b;
    });
    console.log(staple, drinks);
    for (let i = 0; i < m; i++) {
        if (staple[i] >= x) {
            break;
        }
        for (let j = 0; j < n; j++) {
            console.log(staple[i], drinks[j]);
            if (staple[i] + drinks[j] > x) {
                break;
            }
            count++;
        }
    }
    return count;
}
let staple = [10, 20, 5],
    drinks = [5, 5, 2],
    x = 15;
let res = breakfastNumber(staple, drinks, x);
console.log(res);
