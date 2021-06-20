import Comparator from "../../utils/comparator/Comparator";
import { ICallBacks } from "./sortCallbacks";

/**
 * @typedef {Object} SorterCallbacks
 * @property {function(a: *, b: *)} compareCallback - If provided then all elements comparisons
 *  will be done through this callback.
 * @property {function(a: *)} visitingCallback - If provided it will be called each time the sorting
 *  function is visiting the next element.
 */
export default class Sort<T> {
    callbacks: ICallBacks<T>;
    comparator: Comparator<T>;
    constructor(callbacks: ICallBacks<T>) {
        this.callbacks = this.initSortingCallbacks(callbacks);
        this.comparator = new Comparator<T>(this.callbacks.compareCallback);
    }

    /**
     * @param {SorterCallbacks} originalCallbacks
     * @returns {SorterCallbacks}
     */
    initSortingCallbacks(originalCallbacks: ICallBacks<T>): ICallBacks<T> {
        const callbacks = originalCallbacks || {};
        const stubCallback = () => {};

        callbacks.compareCallback =
            originalCallbacks.compareCallback || undefined;
        callbacks.visitingCallback =
            originalCallbacks.visitingCallback || stubCallback;
        return callbacks;
    }

    // sort(): never {
    //     throw new Error("sort method must be implemented");
    // }
}
