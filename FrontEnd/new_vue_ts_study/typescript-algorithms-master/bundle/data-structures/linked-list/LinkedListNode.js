"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var LinkListNode = (function () {
    function LinkListNode(value, next) {
        if (next === void 0) { next = null; }
        this.value = value;
        this.next = next;
    }
    LinkListNode.prototype.toString = function (callback) {
        return callback ? callback(this.value) : this.value;
    };
    return LinkListNode;
}());
exports.default = LinkListNode;
//# sourceMappingURL=LinkedListNode.js.map