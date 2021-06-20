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

export default function buildTree(
    preorder: number[],
    inorder: number[]
): TreeNode | null {
    if (preorder.length === 0) return null;
    const root = new TreeNode(preorder[0], null, null);
    let i = 0;
    for (; i < inorder.length; i++) {
        if (preorder[0] === inorder[i]) break;
    }
    root.left = buildTree(preorder.slice(1, i + 1), inorder.slice(0, i));
    root.right = buildTree(preorder.slice(i + 1), inorder.slice(i + 1));
    return root;
}
