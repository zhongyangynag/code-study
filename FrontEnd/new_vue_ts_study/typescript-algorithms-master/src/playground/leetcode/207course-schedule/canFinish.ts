// class [class, preclass]
export default function canFinish(
    numCourses: number,
    prerequisites: number[][]
): boolean {
    let indegrees = new Array(numCourses).fill(0);
    let nextNodes = new Array(numCourses);
    for (let i = 0; i < numCourses; i++) {
        nextNodes[i] = [];
    }

    let queue: number[] = [];
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
        numCourses--;
        for (let cur of nextNodes[pre]) {
            indegrees[cur] -= 1;
            if (indegrees[cur] === 0) queue.push(cur);
        }
    }
    return !numCourses;
}

// class [class, preclass]
function canFinishDfs(numCourses: number, prerequisites: number[][]): boolean {
    let nextNodes: number[][] = new Array(numCourses);
    for (let i = 0; i < numCourses; i++) nextNodes[i] = [];
    for (let [cur, pre] of prerequisites) nextNodes[pre].push(cur);
    let status = new Array(numCourses).fill(0);
    for (let i = 0; i < numCourses; i++)
        if (!dfs(nextNodes, status, i)) return false;
    return true;
}

function dfs(nextNodes: number[][], flags: number[], idx: number): boolean {
    if (flags[idx] === 1) return false;
    if (flags[idx] === -1) return true;
    flags[idx] = 1;
    for (let node of nextNodes[idx])
        if (!dfs(nextNodes, flags, node)) return false;
    flags[idx] = -1;
    return true;
}

canFinish(3, [
    [1, 0],
    [1, 2],
    [0, 1],
]);

// [1, 2], [2, 3], [3, 1]
// [1, 2], [2, 1]
