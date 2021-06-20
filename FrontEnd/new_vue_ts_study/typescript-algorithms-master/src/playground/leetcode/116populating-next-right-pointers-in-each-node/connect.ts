class Node {
    val: number | null;
    left: Node | null;
    right: Node | null;
    next: Node | null;
    constructor(val: number, left: Node, right: Node, next: Node) {
        this.val = val === undefined ? null : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
        this.next = next === undefined ? null : next;
    }
}

export default function connect(root: Node | null): Node | null {
    if (!root) return root;
    dfs(root, null);
    return root;
}

function dfs(node: Node | null, next: Node | null) {
    if (node) {
        node.next = next;
        dfs(node.left, node.right);
        dfs(node.right, node.next !== null ? node.next.left : null);
    }
}

export function connectP(root: Node | null): Node | null {
    if (!root) return root;
    root.next = null;
    if (root.left && root.right) dfsP(root.left, root.right);
    return root;
}

function dfsP(left: Node, right: Node) {
    left.next = right;
    if (left.left && left.right && right.left && right.right) {
        dfsP(left.left, left.right);
        dfsP(left.right, right.left);
        dfsP(right.left, right.right);
        right.next = null;
    }
}

/* 
输出：
[1,#,2,3,#,4,5,6]
预期结果：
[1,#,2,3,#,4,5,6,7,#]
 */
