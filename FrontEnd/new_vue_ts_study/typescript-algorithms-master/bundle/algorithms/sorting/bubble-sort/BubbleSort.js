"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var __spreadArrays = (this && this.__spreadArrays) || function () {
    for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
    for (var r = Array(s), k = 0, i = 0; i < il; i++)
        for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
            r[k] = a[j];
    return r;
};
Object.defineProperty(exports, "__esModule", { value: true });
var Sort_1 = require("../Sort");
var BubbleSort = (function (_super) {
    __extends(BubbleSort, _super);
    function BubbleSort() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    BubbleSort.prototype.sort = function (originalArr) {
        var _a;
        var swapped = false;
        var array = __spreadArrays(originalArr);
        for (var i = 1; i < array.length; i += 1) {
            swapped = false;
            this.callbacks.visitingCallback &&
                this.callbacks.visitingCallback(array[i]);
            for (var j = 0; j < array.length - i; j += 1) {
                this.callbacks.visitingCallback &&
                    this.callbacks.visitingCallback(array[j]);
                if (this.comparator.lessThan(array[j + 1], array[j])) {
                    _a = [array[j + 1], array[j]], array[j] = _a[0], array[j + 1] = _a[1];
                    swapped = true;
                }
            }
            if (!swapped) {
                return array;
            }
        }
        return array;
    };
    return BubbleSort;
}(Sort_1.default));
exports.default = BubbleSort;
//# sourceMappingURL=BubbleSort.js.map