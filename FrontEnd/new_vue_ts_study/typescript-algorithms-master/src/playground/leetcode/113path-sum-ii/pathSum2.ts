/**
 * Definition for a binary tree node.
 */
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

export default function pathSum(
    root: TreeNode | null,
    sum: number
): number[][] {
    let nodeSet: number[][] = [];
    if (!root) return nodeSet;
    dfs(root, [], nodeSet, sum, 0);
    return nodeSet;
}

function dfs(
    node: TreeNode,
    nodes: number[],
    nodesSet: number[][],
    sum: number,
    curSum: number
) {
    let slice = nodes.slice();
    slice.push(node.val);
    if (!node.left && !node.right && curSum + node.val === sum) {
        nodesSet.push(slice);
    }
    node.left && dfs(node.left, slice, nodesSet, sum, curSum + node.val);
    node.right && dfs(node.right, slice, nodesSet, sum, curSum + node.val);
}
