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

// 出队列 queue.shift();
// 入队列 queue.push(1);

export default function levelOrderBottom(root: TreeNode | null): number[][] {
    if (!root) return [];
    let queue: TreeNode[] = [];
    let res: number[][] = [];
    queue.push(root);
    while (queue.length) {
        let i = queue.length;
        let list: number[] = [];
        while (i !== 0) {
            let currNode = queue.shift() as TreeNode;
            if (currNode.left) queue.push(currNode.left);
            if (currNode.right) queue.push(currNode.right);
            list.push(currNode.val);
            i--;
        }
        res.unshift(list);
    }
    return res;
}
