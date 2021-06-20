function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    let indegrees = new Array(numCourses).fill(0);
    let nextNodes = new Array(numCourses);
    for (let i = 0; i < numCourses; i++) {
        nextNodes[i] = [];
    }

    let queue: number[] = [];
    let result: number[] = [];
    // push
    // shilft

    for (let [cur, pre] of prerequisites) {
        indegrees[cur] += 1; // 当前节点入度 + 1；
        nextNodes[pre].push(cur); // 前驱节点添加新边边；
    }

    for (let i = 0; i < numCourses; i++) {
        if (indegrees[i] === 0) queue.push(i);
    }

    while (queue.length) {
        let pre = queue.shift() as number;
        result.push(pre);
        numCourses--;
        for (let cur of nextNodes[pre]) {
            indegrees[cur] -= 1;
            if (indegrees[cur] === 0) queue.push(cur);
        }
    }
    return !numCourses ? result : [];
}

export default function findOrderDfs(
    numCourses: number,
    prerequisites: number[][]
): number[] {
    let flags: number[] = new Array(numCourses).fill(0);
    let result: number[] = [];
    let nextNodes: number[][] = new Array(numCourses);
    for (let i = 0; i < numCourses; i++) nextNodes[i] = [];
    for (let [cur, pre] of prerequisites) nextNodes[pre].push(cur);
    for (let i = 0; i < numCourses; i++) {
        if (!dfs(nextNodes, flags, result, i)) return [];
    }
    return result;
}

function dfs(
    nextNodes: number[][],
    flags: number[],
    result: number[],
    idx: number
) {
    if (flags[idx] === 1) return false;
    if (flags[idx] === -1) return true;
    flags[idx] = 1;
    result.push(idx);
    for (let node of nextNodes[idx]) {
        if (!dfs(nextNodes, flags, result, node)) return false;
    }
    flags[idx] = -1;
    return true;
}

let result = findOrder(4, [
    [1, 0],
    [1, 2],
    [0, 3],
]);
console.log(result);
