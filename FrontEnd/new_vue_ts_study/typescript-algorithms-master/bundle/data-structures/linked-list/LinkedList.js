"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var LinkedListNode_1 = require("../linked-list/LinkedListNode");
var Comparator_1 = require("../../utils/comparator/Comparator");
var LinkedList = (function () {
    function LinkedList(compareFunc) {
        this.head = null;
        this.tail = null;
        this.compare = compareFunc ? new Comparator_1.default(compareFunc) : null;
    }
    LinkedList.prototype.prepend = function (value) {
        var newNode = new LinkedListNode_1.default(value, this.head);
        this.head = newNode;
        if (!this.tail) {
            this.tail = newNode;
        }
        return this;
    };
    LinkedList.prototype.append = function (value) {
        var newNode = new LinkedListNode_1.default(value);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
            return this;
        }
        if (this.tail) {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        return this;
    };
    LinkedList.prototype.delete = function (value) {
        if (!this.compare) {
            throw new Error("you need to provide compareFunc when instantiate for this method.");
        }
        if (!this.head) {
            return null;
        }
        var deletedNode = null;
        while (this.head && this.compare.equal(this.head.value, value)) {
            deletedNode = this.head;
            this.head = this.head.next;
        }
        var currentNode = this.head;
        if (currentNode !== null) {
            while (currentNode.next) {
                if (this.compare.equal(currentNode.next.value, value)) {
                    deletedNode = currentNode.next;
                    currentNode.next = currentNode.next.next;
                }
                else {
                    currentNode = currentNode.next;
                }
            }
        }
        if (this.tail && this.compare.equal(this.tail.value, value)) {
            this.tail = currentNode;
        }
        return deletedNode;
    };
    LinkedList.prototype.deleteHead = function () {
        if (!this.head) {
            return null;
        }
        var deletedHead = this.head;
        if (this.head.next) {
            this.head = this.head.next;
        }
        else {
            this.head = null;
            this.tail = null;
        }
        return deletedHead;
    };
    LinkedList.prototype.find = function (value, callback) {
        if (!this.compare) {
            throw new Error("you need to provide compareFunc when instantiate for this method.");
        }
        if (!this.head) {
            return null;
        }
        var currentNode = this.head;
        while (currentNode) {
            if (callback && callback(currentNode.value)) {
                return currentNode;
            }
            if (value !== undefined &&
                this.compare.equal(currentNode.value, value)) {
                return currentNode;
            }
            currentNode = currentNode.next;
        }
        return null;
    };
    LinkedList.prototype.toArray = function () {
        var nodes = [];
        var currentNode = this.head;
        while (currentNode) {
            nodes.push(currentNode);
            currentNode = currentNode.next;
        }
        return nodes;
    };
    LinkedList.prototype.toString = function (callback) {
        return this.toArray()
            .map(function (node) { return node.toString(callback); })
            .toString();
    };
    LinkedList.prototype.reverse = function () {
        var currNode = this.head;
        var prevNode = null;
        var nextNode = null;
        while (currNode) {
            nextNode = currNode.next;
            currNode.next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        this.tail = this.head;
        this.head = prevNode;
        return this;
    };
    return LinkedList;
}());
exports.default = LinkedList;
//# sourceMappingURL=LinkedList.js.map