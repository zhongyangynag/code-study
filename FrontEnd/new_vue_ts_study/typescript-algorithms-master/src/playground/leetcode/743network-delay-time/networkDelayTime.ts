const maxDis = 0x0000ffff;
export default function networkDelayTime(
    times: number[][],
    N: number,
    K: number
): number {
    /* 初始化 */
    let nextNodes: number[][][] = new Array(N + 1);
    // 提取相邻节点
    let visited: number[] = new Array(N + 1);
    // 访问数组
    let dis: number[] = new Array(N + 1);
    // 到顶点的最短距离
    let preNode: number[] = new Array(N + 1);
    // 最短前置节点
    for (let i = 1; i < N + 1; i++) {
        // 初始化 nextNodes 和 dis
        nextNodes[i] = [];
        if (i === K) {
            dis[i] = 0;
        } else {
            dis[i] = maxDis;
        }
    }
    visited[K] = 1;
    // 顶点已访问
    for (let [cur, next, time] of times) {
        // 添加相邻节点
        nextNodes[cur].push([next, time]);
    }
    /* 广度优先遍历 */
    function update(idx: number) {
        let min = 0;
        for (let [nxt, time] of nextNodes[idx]) {
            min = time + dis[idx];
            if (min < dis[nxt] && !visited[nxt]) {
                dis[nxt] = min;
                preNode[nxt] = idx;
            }
        }
    }
    update(K);
    for (let i = 1; i < N; i++) {
        let minDis = maxDis;
        let idx = 1;
        for (let j = idx; j < dis.length; j++) {
            // 获取本轮得出到顶点最短路径的节点
            if (dis[j] < minDis && !visited[j]) {
                minDis = dis[j];
                idx = j;
            }
        }
        visited[idx] = 1;
        update(idx);
    }

    let res = Math.max(...dis.slice(1));
    return res === maxDis ? -1 : res;
}

let res = networkDelayTime(
    [
        [2, 1, 1],
        [2, 3, 1],
        [3, 4, 1],
    ],
    4,
    2
);

console.log(res);
