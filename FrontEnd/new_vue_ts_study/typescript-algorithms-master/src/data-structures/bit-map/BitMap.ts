export default class BitMap {
    private store: number[];
    constructor(size: number) {
        this.store = new Array(size).fill(0);
    }
    add(num: number) {
        const storeOffset = Math.floor(num / 32);
        const bitOffset = num % 32;
        let value = this.store[storeOffset];
        value = value | (1 << bitOffset);
        this.store[storeOffset] = value;
    }
    has(num: number) {
        let storeOffset = Math.floor(num / 32);
        let bitOffset = num % 32;
        let value = this.store[storeOffset] & (1 << bitOffset);
        return value !== 0;
    }
}
