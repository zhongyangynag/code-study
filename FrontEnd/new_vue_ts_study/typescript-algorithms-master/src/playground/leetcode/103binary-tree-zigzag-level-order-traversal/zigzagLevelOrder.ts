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

export default function zigzagLevelOrder(root: TreeNode | null): number[][] {
    if (!root) return [];
    let res: number[][] = [];
    let queue: TreeNode[] = [];
    /**
     * FIFO FORWARD
     * queue.push()
     * queue.shift()
     *
     * FIFO BACKWARD
     * queue.unshift()
     * queue.pop()
     */
    queue.push(root);
    let isForward = false;
    while (queue.length > 0) {
        let i = queue.length;
        let curList: number[] = [];
        while (i > 0) {
            let curr: TreeNode;
            if (isForward) {
                curr = queue.shift() as TreeNode;
                if (curr.right) queue.push(curr.right);
                if (curr.left) queue.push(curr.left);
            } else {
                curr = queue.pop() as TreeNode;
                if (curr.left) queue.unshift(curr.left);
                if (curr.right) queue.unshift(curr.right);
            }
            curList.push(curr.val);
            i--;
        }
        isForward = !isForward;
        res.push(curList);
    }
    return res;
}

let res = zigzagLevelOrder(
    new TreeNode(
        3,
        new TreeNode(9, new TreeNode(8), new TreeNode(12)),
        new TreeNode(20, new TreeNode(15), new TreeNode(7))
    )
);

console.log(res);
