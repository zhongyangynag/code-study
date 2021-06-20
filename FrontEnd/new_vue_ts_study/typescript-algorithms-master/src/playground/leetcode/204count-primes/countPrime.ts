function countPrimes(n: number): number {
    let isPrime: boolean[] = new Array(n - 1).fill(true);
    let count = 0;
    for (let i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (let j = i + i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

function isPrime(n: number): number {
    for (let i = 2; i * i <= n; i++) {
        if (n % i === 0) return 0;
    }
    return 1;
}
