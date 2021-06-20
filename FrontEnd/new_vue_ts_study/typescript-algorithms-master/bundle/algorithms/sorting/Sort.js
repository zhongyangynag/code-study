"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Comparator_1 = require("../../utils/comparator/Comparator");
var Sort = (function () {
    function Sort(callbacks) {
        this.callbacks = this.initSortingCallbacks(callbacks);
        this.comparator = new Comparator_1.default(this.callbacks.compareCallback);
    }
    Sort.prototype.initSortingCallbacks = function (originalCallbacks) {
        var callbacks = originalCallbacks || {};
        var stubCallback = function () { };
        callbacks.compareCallback =
            originalCallbacks.compareCallback || undefined;
        callbacks.visitingCallback =
            originalCallbacks.visitingCallback || stubCallback;
        return callbacks;
    };
    return Sort;
}());
exports.default = Sort;
//# sourceMappingURL=Sort.js.map