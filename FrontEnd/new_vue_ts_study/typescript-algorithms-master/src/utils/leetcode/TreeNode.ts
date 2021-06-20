import Queue from "../../data-structures/queue/Queue";

export default class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }

    // static BuildTree(nodes: Array<number | null>): TreeNode {
    //     let root = new TreeNode();
    //     let queue = new Queue<TreeNode>();
    //     queue.enqueue(root);
    //     let i = 0;
    //     while (!queue.isEmpty()) {
    //         let curr = queue.dequeue();
    //         if (curr && curr !== null) {
    //             curr.val = nodes[i];
    //             i++;
    //             curr.left = new TreeNode();
    //             queue.enqueue(curr.left);
    //             curr.right = new TreeNode();
    //             queue.enqueue(curr.right);
    //         }
    //     }
    //     return root;
    // }
}
