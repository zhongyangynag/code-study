import Comparator from "../../utils/comparator/Comparator";
import { ICompareFunction } from "../../utils/comparator/compare";

export default class BinaryTreeNode<T> {
    public left: BinaryTreeNode<T> | null;
    public right: BinaryTreeNode<T> | null;
    public parent: BinaryTreeNode<T> | null;
    public value: T | null;
    public nodeComparator: Comparator<T | null>;

    constructor(value: T | null = null) {
        this.left = null;
        this.right = null;
        this.parent = null;
        this.value = value;
        this.nodeComparator = new Comparator<T | null>();
    }

    public get leftHeight(): number {
        if (!this.left) return 0;
        return this.left.height;
    }

    public get rightHeight(): number {
        if (!this.right) return 0;
        return this.right.height;
    }

    public get height(): number {
        return Math.max(this.rightHeight, this.leftHeight);
    }

    public get balanceFactor(): number {
        return this.leftHeight - this.rightHeight;
    }

    public setValue(value: T | null) {
        this.value = value;
        return this;
    }

    public setLeft(node: BinaryTreeNode<T> | null) {
        if (this.left && this.left.parent) {
            this.left.parent = null;
        }

        this.left = node;
        if (this.left) this.left.parent = this;
        return this;
    }

    public setRight(node: BinaryTreeNode<T> | null) {
        if (this.right && this.right.parent) {
            this.right.parent = null;
        }

        this.right = node;
        if (this.right) this.right.parent = this;
        return this;
    }

    public removeChild(nodeToRemove: BinaryTreeNode<T>) {
        if (
            this.left &&
            this.nodeComparator.equal(this.left.value, nodeToRemove.value)
        ) {
            this.left = null;
            return true;
        }
        if (
            this.right &&
            this.nodeComparator.equal(this.right.value, nodeToRemove.value)
        ) {
            this.right = null;
            return true;
        }
        return false;
    }
}
