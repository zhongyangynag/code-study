"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var LinkedList_1 = require("../linked-list/LinkedList");
var Queue = (function () {
    function Queue() {
        this.linkedList = new LinkedList_1.default();
    }
    Queue.prototype.isEmpty = function () {
        return !this.linkedList.head;
    };
    Queue.prototype.peek = function () {
        if (!this.linkedList.head) {
            return null;
        }
        return this.linkedList.head.value;
    };
    Queue.prototype.enqueue = function (value) {
        this.linkedList.append(value);
    };
    Queue.prototype.dequeue = function () {
        var removedHead = this.linkedList.deleteHead();
        return removedHead ? removedHead.value : null;
    };
    Queue.prototype.toString = function (callback) {
        return this.linkedList.toString(callback);
    };
    return Queue;
}());
exports.default = Queue;
//# sourceMappingURL=Queue.js.map