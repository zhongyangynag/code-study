// Definition for a binary tree node.
class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
}

export default function hasPathSum(
    root: TreeNode | null,
    sum: number
): boolean {
    if (!root) {
        return false;
    }
    return dfs(root, sum, 0);
}

function dfs(node: TreeNode, sum: number, curSum: number): boolean {
    if (!node.left && !node.right) {
        return curSum + node.val === sum ? true : false;
    }
    if (node.left && dfs(node.left, sum, curSum + node.val)) {
        return true;
    }
    if (node.right && dfs(node.right, sum, curSum + node.val)) {
        return true;
    }
    return false;
}

let test = new TreeNode(1);
test.left = new TreeNode(2);

let res = hasPathSum(test, 1);

console.log(res);
