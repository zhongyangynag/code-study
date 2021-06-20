import LinkedList from "../linked-list/LinkedList";

export default class Stack<T> {
    private linkedList: LinkedList<T>;
    constructor() {
        // We're going to implement Stack based on LinkedList since these
        // structures are quite similar. Compare push/pop operations of the Stack
        // with prepend/deleteHead operations of LinkedList.
        this.linkedList = new LinkedList<T>();
    }

    /**
     * @return {boolean}
     */
    isEmpty(): boolean {
        return !this.linkedList.head;
    }

    /**
     * @return {T}
     */
    peek(): T | null {
        // If the linked list is empty then there is nothing to peek from.
        // Just read the value from the start of linked list without deleting it.
        // I write in this way because the fucking strictNullChecks.
        return this.linkedList.head ? this.linkedList.head.value : null;
    }

    /**
     * @return {T}
     */
    pop(): T | null {
        // Let's try to delete the first node (the head) from the linked list.
        // If there is no head (the linked list is empty) just return null.
        const removedHead = this.linkedList.deleteHead();
        return removedHead ? removedHead.value : null;
    }

    /**
     * @param {T} value
     */
    push(value: T) {
        // Pushing means to lay the value on top of the stack. Therefore let's just add
        // the new value at the start of the linked list.
        this.linkedList.prepend(value);
    }

    /**
     * @return {*[]}
     */
    toArray(): T[] {
        return this.linkedList
            .toArray()
            .map((linkedListNode) => linkedListNode.value);
    }

    /**
     * @param {function} [callback]
     * @return {string}
     */
    toString(callback?: (value: T) => string) {
        return this.linkedList.toString(callback);
    }
}
