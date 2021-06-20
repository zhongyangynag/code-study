import TreeNode from "../../../utils/leetcode/TreeNode";
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
const check = (p: TreeNode | null, q: TreeNode | null): boolean => {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p.val === q.val && check(p.left, q.right) && check(p.right, q.left);
};
var isSymmetric = function (root: TreeNode | null): boolean {
    return check(root, root);
};

// TreeNode.BuildTree([5, 4, 1, null, 1, null, 4, 2, null, 2, null]);
let root = new TreeNode(
    5,
    new TreeNode(5, new TreeNode(2), null),
    new TreeNode(1, new TreeNode(2), null)
);

let res = isSymmetric(root);
console.log(res);
