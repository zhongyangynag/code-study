import BinaryTreeNode from "../BinaryTreeNode";
import { ICompareFunction } from "../../../utils/comparator/compare";
import Comparator from "../../../utils/comparator/Comparator";

export type INodeCompareFunction<T> = ICompareFunction<T | null>;

export default class BinarySearchTreeNode<T> extends BinaryTreeNode<T> {
    public left: BinarySearchTreeNode<T> | null;
    public right: BinarySearchTreeNode<T> | null;
    public parent: BinarySearchTreeNode<T> | null;
    private compareFunc: INodeCompareFunction<T> | undefined;
    constructor(
        value: T | null = null,
        compareFunc: ICompareFunction<T | null> | undefined = undefined
    ) {
        super(value);
        this.left = null;
        this.right = null;
        this.parent = null;

        this.compareFunc = compareFunc;
        this.nodeComparator = new Comparator<T | null>(compareFunc);
    }

    public insert(value: T): BinarySearchTreeNode<T> {
        if (this.nodeComparator.equal(this.value, null)) {
            this.value;
            return this;
        }

        if (this.nodeComparator.lessThan(this.value, value)) {
            if (this.right) return this.right.insert(value);
            const newNode = new BinarySearchTreeNode<T>(
                value,
                this.compareFunc
            );
            this.setRight(newNode);
            return newNode;
        }

        if (this.nodeComparator.greaterThan(this.value, value)) {
            if (this.left) return this.left.insert(value);
            const newNode = new BinarySearchTreeNode<T>(
                value,
                this.compareFunc
            );
            this.setLeft(newNode);
            return newNode;
        }
        return this;
    }

    public find(value: T): BinarySearchTreeNode<T> | null {
        if (this.nodeComparator.equal(this.value, value)) {
            return this;
        }

        if (this.nodeComparator.greaterThan(this.value, value) && this.left) {
            return this.left.find(value);
        }

        if (this.nodeComparator.lessThan(this.value, value) && this.right) {
            return this.right.find(value);
        }
        return null;
    }

    public contains(value: T): boolean {
        return !!this.find(value);
    }

    public remove(value: T) {
        const nodeToRemove = this.find(value);

        if (!nodeToRemove) {
            throw new Error("Item not found in the tree");
        }

        const { parent } = nodeToRemove;

        if (!nodeToRemove.left && !nodeToRemove.right) {
            // Node is a leaf and thus has no children.
            if (parent) {
                // Node has a parent. Just remove the pointer to this node from the parent.
                parent.removeChild(nodeToRemove);
            } else {
                // Node has no parent. Just erase current node value.
                nodeToRemove.setValue(null);
            }
        } else if (nodeToRemove.left && nodeToRemove.right) {
            // Node has two children.
            // Find the next biggest value (minimum value in the right branch)
            // and replace current value node with that next biggest value.
            const nextBiggerNode = nodeToRemove.right.findMin();
            if (
                !this.nodeComparator.equal(nextBiggerNode, nodeToRemove.right)
            ) {
                this.remove(nextBiggerNode.value);
                nodeToRemove.setValue(nextBiggerNode.value);
            } else {
                // In case if next right value is the next bigger one and it doesn't have left child
                // then just replace node that is going to be deleted with the right node.
                nodeToRemove.setValue(nodeToRemove.right.value);
                nodeToRemove.setRight(nodeToRemove.right.right);
            }
        } else {
            // Node has only one child.
            // Make this child to be a direct child of current node's parent.
            /** @var BinarySearchTreeNode */
            const childNode = nodeToRemove.left || nodeToRemove.right;

            if (parent) {
                parent.replaceChild(nodeToRemove, childNode);
            } else {
                BinaryTreeNode.copyNode(childNode, nodeToRemove);
            }
        }
    }

    public findMin(): BinarySearchTreeNode<T> {
        if (!this.left) {
            return this;
        }
        return this.left.findMin();
    }
}
