import { BloomFilterStorage } from "./BloomFilterStorage";

describe("test BloomFilter", () => {
    let bloomStorage: BloomFilterStorage;

    beforeEach(() => {
        bloomStorage = new BloomFilterStorage(100);
    });

    it("should has method named insert and mayContain", () => {
        expect(typeof bloomStorage.setVal).toBe("function");
        expect(typeof bloomStorage.getVal).toBe("function");
    });

    it("should insert values correctly and return true when checking for inserted values", () => {
        bloomStorage.setVal(0);
        bloomStorage.setVal(99);

        expect(bloomStorage.getVal(0)).toBe(true);
        expect(bloomStorage.getVal(99)).toBe(true);
        expect(bloomStorage.getVal(44)).toBe(false);
    });
});
