import { BloomFilterStorage } from "./BloomFilterStorage";

export default class BloomFilter {
    private size: number;
    private storage: BloomFilterStorage;

    constructor(size = 100) {
        this.size = size;
        this.storage = new BloomFilterStorage(size);
    }

    public insert(item: string) {
        let hashValues = this.getHashValues(item);
        hashValues.forEach((item: number) => this.storage.setVal(item));
    }

    public mayContain(item: string): boolean {
        let hashValues = this.getHashValues(item);

        for (let hashIdx = 0; hashIdx < hashValues.length; hashIdx++) {
            if (!this.storage.getVal(hashValues[hashIdx])) {
                return false;
            }
        }
        return true;
    }

    private hash1(item: string): number {
        let hash = 0;

        for (let charIndex = 0; charIndex < item.length; charIndex += 1) {
            const char = item.charCodeAt(charIndex);
            hash = (hash << 5) + hash + char;
            hash &= hash; // Convert to 32bit integer
            hash = Math.abs(hash);
        }

        return hash % this.size;
    }

    private hash2(item: string): number {
        let hash = 5381;

        for (let charIndex = 0; charIndex < item.length; charIndex += 1) {
            const char = item.charCodeAt(charIndex);
            hash = (hash << 5) + hash + char; /* hash * 33 + c */
        }

        return Math.abs(hash % this.size);
    }

    private hash3(item: string): number {
        let hash = 0;

        for (let charIndex = 0; charIndex < item.length; charIndex += 1) {
            const char = item.charCodeAt(charIndex);
            hash = (hash << 5) - hash;
            hash += char;
            hash &= hash; // Convert to 32bit integer
        }

        return Math.abs(hash % this.size);
    }

    private getHashValues(item: string): [number, number, number] {
        return [this.hash1(item), this.hash2(item), this.hash3(item)];
    }
}
