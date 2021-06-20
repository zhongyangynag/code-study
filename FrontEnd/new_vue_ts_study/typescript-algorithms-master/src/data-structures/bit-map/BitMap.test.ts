import BitMap from "./BitMap";

describe("test BitMap", () => {
    let bitmap: BitMap;

    let testingArr = [0, 40, 80, 120];

    beforeEach(() => {
        bitmap = new BitMap(4);
    });

    it("should has method named has and add", () => {
        expect(typeof bitmap.add).toBe("function");
        expect(typeof bitmap.has).toBe("function");
    });
    it("should add number correctly and return whether a numberis in it correctly", () => {
        testingArr.forEach((num: number) => bitmap.add(num));
        testingArr.forEach((num: number) =>
            expect(bitmap.has(num)).toBeTruthy()
        );
        expect(bitmap.has(88)).toBeFalsy();
    });
});
