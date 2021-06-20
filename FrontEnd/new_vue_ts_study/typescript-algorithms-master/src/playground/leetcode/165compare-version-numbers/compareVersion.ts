function compareVersion(version1: string, version2: string): number {
    let v1s = version1.split(".");
    let v2s = version2.split(".");
    let l1 = v1s.length;
    let l2 = v2s.length;
    let maxLen = Math.max(l1, l2);
    let i = 0;
    while (i < maxLen) {
        let n1 = 0,
            n2 = 0;

        if (i < l1) {
            n1 = parseInt(v1s[i]);
        }

        if (i < l2) {
            n2 = parseInt(v2s[i]);
        }

        if (n1 > n2) {
            return 1;
        } else if (n1 < n2) {
            return -1;
        }
        i++;
    }
    return 0;
}
