export default function findJudge(N: number, trust: number[][]): number {
    // [human, trust]
    let nextNodes: number[][] = new Array(N + 1);
    let truthes: number[] = new Array(N + 1).fill(0);
    let judges: number[] = [];

    for (let i = 1; i <= N; i++) {
        nextNodes[i] = [];
    }
    for (let [human, truth] of trust) {
        nextNodes[human].push(truth);
        truthes[truth]++;
        if (truthes[truth] === N - 1) judges.push(truth);
    }
    for (let mayJudge of judges) {
        if (nextNodes[mayJudge].length === 0) return mayJudge;
    }
    return N === 1 ? 1 : -1;
}
