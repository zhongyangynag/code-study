"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var LinkedList_1 = require("../linked-list/LinkedList");
var Stack = (function () {
    function Stack() {
        this.linkedList = new LinkedList_1.default();
    }
    Stack.prototype.isEmpty = function () {
        return !this.linkedList.head;
    };
    Stack.prototype.peek = function () {
        return this.linkedList.head ? this.linkedList.head.value : null;
    };
    Stack.prototype.pop = function () {
        var removedHead = this.linkedList.deleteHead();
        return removedHead ? removedHead.value : null;
    };
    Stack.prototype.push = function (value) {
        this.linkedList.prepend(value);
    };
    Stack.prototype.toArray = function () {
        return this.linkedList
            .toArray()
            .map(function (linkedListNode) { return linkedListNode.value; });
    };
    Stack.prototype.toString = function (callback) {
        return this.linkedList.toString(callback);
    };
    return Stack;
}());
exports.default = Stack;
//# sourceMappingURL=Stack.js.map