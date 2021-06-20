import { AbstractSet } from "../interface/AbstractSet";
export declare class ArraySet<T> extends AbstractSet<T> {
    private set;
    private count;
    constructor();
    readonly Size: number;
    has(item: T): boolean;
    findIndex(item: T): number;
    add(item: T): this;
    entries(): Array<T>;
    remove(item: T): boolean;
    union(set: AbstractSet<T>): Array<T>;
    intersect(set: AbstractSet<T>): Array<T>;
    diff(set: AbstractSet<T>): Array<T>;
}
