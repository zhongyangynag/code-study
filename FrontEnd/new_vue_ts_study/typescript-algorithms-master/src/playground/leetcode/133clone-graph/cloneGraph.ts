// Definition for a Node.
export class Node {
    val: number;
    neighbors: Node[];
    constructor(val?: number, neighbors?: Node[]) {
        this.val = val ? val : 0;
        this.neighbors = neighbors ? neighbors : [];
    }
}

/**
 * @param {Node} node
 * @return {Node}
 */
export default function cloneGraph(node: Node) {
    if (!node) return node;
    let queue: Node[] = [];
    let visisted: Map<Node, Node> = new Map();
    queue.push(node);
    visisted.set(node, new Node(node.val, []));
    while (queue.length > 0) {
        let cur = queue.shift() as Node;
        for (let neighbor of cur.neighbors) {
            if (!visisted.has(neighbor)) {
                queue.push(neighbor);
                visisted.set(neighbor, new Node(neighbor.val, []));
            }
            (visisted.get(cur) as Node).neighbors.push(
                visisted.get(neighbor) as Node
            );
        }
    }
    return visisted.get(node);
}

//  1 --- 2 ---
//          ---
//    --- 3
//
//
//
//
