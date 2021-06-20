import TreeNode from "../../../utils/leetcode/TreeNode";
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

export default function minDepth(root: TreeNode | null): number {
    if (!root) return 0;
    if (!root.left && !root.right) return 1;
    let leftHeight = root.left ? minDepth(root.left) : Number.MAX_VALUE;
    let rightHeight = root.right ? minDepth(root.right) : Number.MAX_VALUE;
    return Math.min(leftHeight, rightHeight) + 1;
}
