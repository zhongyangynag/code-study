import BloomFilter from "./BloomFilter";

describe("test BloomFilter", () => {
    let bloomFilter: BloomFilter;

    let testCases = ["foo", "bar", "hun"];

    beforeEach(() => {
        bloomFilter = new BloomFilter();
    });

    it("should has method named insert and mayContain", () => {
        expect(typeof bloomFilter.insert).toBe("function");
        expect(typeof bloomFilter.mayContain).toBe("function");
    });

    it("should insert strings correctly and return true when checking for inserted values", () => {
        testCases.forEach((item: string) => {
            bloomFilter.insert(item);
        });

        expect(bloomFilter.mayContain("foo")).toBeTruthy();
        expect(bloomFilter.mayContain("bar")).toBeTruthy();
        expect(bloomFilter.mayContain("hun")).toBeTruthy();

        expect(bloomFilter.mayContain("abc")).toBeFalsy();
    });
});
