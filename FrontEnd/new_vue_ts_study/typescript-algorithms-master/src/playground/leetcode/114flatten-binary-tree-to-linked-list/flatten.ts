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

/**
 Do not return anything, modify root in-place instead.
 */

//TODO

function flatten(root: TreeNode | null): void {
    dfs(root);
}

function dfs(node: TreeNode | null): TreeNode | null {
    if (!node) return null;
    if (!node.left) return node;
    let left = dfs(node.left) as TreeNode;
    left.left = dfs(node.right);
    return left;
}
