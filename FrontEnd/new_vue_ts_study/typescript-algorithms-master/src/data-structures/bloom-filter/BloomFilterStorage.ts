export class BloomFilterStorage {
    private storage: boolean[];
    constructor(size: number) {
        this.storage = new Array(size).fill(false);
    }
    public setVal(index: number) {
        this.storage[index] = true;
    }
    public getVal(index: number): boolean {
        return this.storage[index];
    }
}
