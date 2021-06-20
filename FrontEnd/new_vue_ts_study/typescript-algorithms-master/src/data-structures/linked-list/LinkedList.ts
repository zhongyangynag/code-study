import LinkedListNode from "../linked-list/LinkedListNode";
import Comparator from "../../utils/comparator/Comparator";
import { ICompareFunction } from "../../utils/comparator/compare";

export default class LinkedList<T> {
    head: LinkedListNode<T> | null;
    tail: LinkedListNode<T> | null;
    private compare?: Comparator<T> | null;
    /**
     * @param {Function} [comparatorFunction]
     */
    constructor(compareFunc?: ICompareFunction<T>) {
        /** @var LinkedListNode */
        this.head = null;
        /** @var LinkedListNode */
        this.tail = null;
        this.compare = compareFunc ? new Comparator<T>(compareFunc) : null;
    }

    /**
     * @param {T} value
     * @return {LinkedList}
     */
    prepend(value: T): LinkedList<T> {
        // Make new node to be a head.
        const newNode = new LinkedListNode(value, this.head);
        this.head = newNode;

        // If there is no tail yet let's make new node a tail.
        if (!this.tail) {
            this.tail = newNode;
        }

        return this;
    }

    /**
     * @param {T} value
     * @return {LinkedList}
     */
    append(value: T): LinkedList<T> {
        const newNode = new LinkedListNode(value);

        // If there is no head yet let's make new node a head.
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;

            return this;
        }

        // Attach new node to the end of linked list.
        if (this.tail) {
            this.tail.next = newNode;
            this.tail = newNode;
        }

        return this;
    }

    /**
     * @param {T} value
     * @return {LinkedListNode}
     */
    delete(value: T): LinkedListNode<T> | null {
        if (!this.compare) {
            throw new Error(
                "you need to provide compareFunc when instantiate for this method."
            );
        }
        if (!this.head) {
            return null;
        }

        let deletedNode = null;

        // If the head must be deleted then make next node that is differ
        // from the head to be a new head.
        while (this.head && this.compare.equal(this.head.value, value)) {
            deletedNode = this.head;
            this.head = this.head.next;
        }

        let currentNode = this.head;

        if (currentNode !== null) {
            // If next node must be deleted then make next node to be a next next one.
            while (currentNode.next) {
                if (this.compare.equal(currentNode.next.value, value)) {
                    deletedNode = currentNode.next;
                    currentNode.next = currentNode.next.next;
                } else {
                    currentNode = currentNode.next;
                }
            }
        }

        // Check if tail must be deleted.
        if (this.tail && this.compare.equal(this.tail.value, value)) {
            this.tail = currentNode;
        }

        return deletedNode;
    }

    deleteHead(): LinkedListNode<T> | null {
        if (!this.head) {
            return null;
        }

        let deletedHead = this.head;
        if (this.head.next) {
            this.head = this.head.next;
        } else {
            this.head = null;
            this.tail = null;
        }

        return deletedHead;
    }

    /**
     * @param {Object} findParams
     * @param {T} findParams.value
     * @param {function} [findParams.callback]
     * @return {LinkedListNode}
     */
    find(value: T, callback: (value: T) => boolean): LinkedListNode<T> | null {
        if (!this.compare) {
            throw new Error(
                "you need to provide compareFunc when instantiate for this method."
            );
        }
        if (!this.head) {
            return null;
        }

        let currentNode: LinkedListNode<T> | null = this.head;

        while (currentNode) {
            // If callback is specified then try to find node by callback.
            if (callback && callback(currentNode.value)) {
                return currentNode;
            }

            // If value is specified then try to compare by value..
            if (
                value !== undefined &&
                this.compare.equal(currentNode.value, value)
            ) {
                return currentNode;
            }

            currentNode = currentNode.next;
        }

        return null;
    }

    /**
     * @return {LinkedListNode[]}
     */
    toArray(): Array<LinkedListNode<T>> {
        const nodes: LinkedListNode<T>[] = [];

        let currentNode = this.head;
        while (currentNode) {
            nodes.push(currentNode);
            currentNode = currentNode.next;
        }

        return nodes;
    }

    /**
     * @param {function} [callback]
     * @return {string}
     */
    toString(callback?: (value: T) => string) {
        return this.toArray()
            .map((node) => node.toString(callback))
            .toString();
    }

    /**
     * Reverse a linked list.
     * @returns {LinkedList}
     */
    reverse(): LinkedList<T> {
        let currNode = this.head;
        let prevNode = null;
        let nextNode = null;

        while (currNode) {
            // Store next node.
            nextNode = currNode.next;

            // Change next node of the current node so it would link to previous node.
            currNode.next = prevNode;

            // Move prevNode and currNode nodes one step forward.
            prevNode = currNode;
            currNode = nextNode;
        }

        // Reset head and tail.
        this.tail = this.head;
        this.head = prevNode;

        return this;
    }
}
