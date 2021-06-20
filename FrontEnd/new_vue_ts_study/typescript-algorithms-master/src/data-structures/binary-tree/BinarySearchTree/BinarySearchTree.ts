import BinarySearchTreeNode, {
    INodeCompareFunction,
} from "./BinarySearchTreeNode";

import Comparator from "../../../utils/comparator/Comparator";

export default class BinarySearchTree<T> {
    public root: BinarySearchTreeNode<T>;
    public nodeComparator: Comparator<T>;
    constructor(nodeCompareFunc: INodeCompareFunction<T>) {
        this.root = new BinarySearchTreeNode(null, nodeCompareFunc);
        this.nodeComparator = this.root.nodeComparator;
    }
    insert(value: T) {
        return this.root.insert(value);
    }

    contains(value: T) {
        return this.root.contains(value);
    }

    remove(value: T) {
        return this.root.remove(value);
    }
}
