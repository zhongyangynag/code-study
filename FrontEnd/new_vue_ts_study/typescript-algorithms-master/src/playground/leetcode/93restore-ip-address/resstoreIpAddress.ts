export default function restoreIpAddresses(s: string): string[] {
    let res: string[] = [];
    dfs(s, 0, [], res);
    return res;
}

function dfs(s: string, pIdx: number, ipParts: string[], res: string[]) {
    if (pIdx === 4) {
        res.push(ipParts.join("."));
        return;
    }

    for (let i = 1; i <= 3 && i <= s.length; i++) {
        let curPart = s.slice(0, i);
        let remainedPart = s.slice(i, s.length);
        if (
            remainedPart.length > 3 * (3 - pIdx) || // avoid remained space not enough
            (curPart.length > 1 && curPart.startsWith("0")) || // avoid ip part likes "010" or "001" and so on.
            parseInt(curPart) > 255 // avoid ip part large than 255
        )
            continue;
        let cIpParts = ipParts.slice();
        cIpParts.push(curPart);
        dfs(remainedPart, pIdx + 1, cIpParts, res);
    }
}

console.log(restoreIpAddresses("25525511135"));
