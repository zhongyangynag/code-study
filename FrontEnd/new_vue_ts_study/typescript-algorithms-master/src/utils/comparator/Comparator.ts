import { ICompareFunction } from "./compare";

export default class Comparator<T> {
    private compare: ICompareFunction<T>;

    /**
     * @param {function(a: *, b: *)} [ICompareFunction] - It may be custom compare function that, let's
     * say may compare custom objects together.
     */
    constructor(compareFunc?: ICompareFunction<T>) {
        this.compare = compareFunc || this.defaultCompare;
    }

    /**
     * Default comparison function. It just assumes that "a" and "b" are strings or numbers.
     * @param {(string|number)} a
     * @param {(string|number)} b
     * @returns {number}
     */
    private defaultCompare<T = string | number>(a: T, b: T): number {
        if (a === b) {
            return 0;
        }
        return a > b ? 1 : -1;
    }

    /**
     * Checks if two variables are equal.
     * @param {*} a
     * @param {*} b
     * @return {boolean}
     */
    equal(a: T, b: T): boolean {
        return this.compare(a, b) === 0;
    }

    /**
     * Checks if variable "a" is greater than "b".
     * @param {*} a
     * @param {*} b
     * @return {boolean}
     */
    greaterThan(a: T, b: T): boolean {
        return this.compare(a, b) > 0;
    }

    /**
     * Checks if variable "a" is less than "b".
     * @param {*} a
     * @param {*} b
     * @return {boolean}
     */
    lessThan(a: T, b: T): boolean {
        return this.compare(a, b) < 0;
    }

    /**
     * Reverses the comparison order.
     */
    reverse(): void {
        const originCompare = this.compare;
        this.compare = (a, b) => originCompare(b, a);
    }
}
