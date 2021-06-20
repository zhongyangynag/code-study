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

export default function postorderTraversal(root: TreeNode | null): number[] {
    let store: number[] = [];
    dfs(root, store);
    return store;
}

function dfs(root: TreeNode | null, store: number[]) {
    if (!root) return;
    dfs(root.left, store);
    dfs(root.right, store);
    store.push(root.val);
}
