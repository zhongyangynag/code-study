import { ICompareFunction } from "../../utils/comparator/compare";

export interface ICallBacks<T> {
    compareCallback?: ICompareFunction<T>;
    visitingCallback?: (a: T) => void;
}
