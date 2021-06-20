export default function canCompleteCircuit(
    gas: number[],
    cost: number[]
): number {
    let gasTotal = 0;
    let distance = gas.length;
    function dfs(idx: number, count: number): boolean {
        if (count >= distance) return true;
        console.log(gasTotal, gas[idx], cost[idx]);
        gasTotal += gas[idx] - cost[idx];
        count++;
        if (gasTotal < 0) return false;
        return dfs((idx + 1) % distance, count);
    }

    for (let i = 0; i < distance; i++) {
        gasTotal = 0;
        console.log(i);
        if (dfs(i, 0)) {
            return i;
        }
    }
    return -1;
}

export function canCompleteCircuitPro(gas: number[], cost: number[]): number {
    let n = gas.length;
    let curr_gas = 0;
    let total_gas = 0;
    let starting_station = 0;

    for (let i = 0; i < n; i++) {
        curr_gas += gas[i] - cost[i];
        total_gas += gas[i] - cost[i];

        if (curr_gas < 0) {
            starting_station = i + 1;
            curr_gas = 0;
        }
    }
    return total_gas >= 0 ? starting_station : -1;
}

let gas = [5, 1, 2, 3, 4];
let cost = [4, 4, 1, 5, 1];

console.log(canCompleteCircuit(gas, cost));
