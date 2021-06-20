"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Comparator = (function () {
    function Comparator(compareFunc) {
        this.compare = compareFunc || this.defaultCompare;
    }
    Comparator.prototype.defaultCompare = function (a, b) {
        if (a === b) {
            return 0;
        }
        return a > b ? 1 : -1;
    };
    Comparator.prototype.equal = function (a, b) {
        return this.compare(a, b) === 0;
    };
    Comparator.prototype.greaterThan = function (a, b) {
        return this.compare(a, b) > 0;
    };
    Comparator.prototype.lessThan = function (a, b) {
        return this.compare(a, b) < 0;
    };
    Comparator.prototype.reverse = function () {
        var originCompare = this.compare;
        this.compare = function (a, b) { return originCompare(b, a); };
    };
    return Comparator;
}());
exports.default = Comparator;
//# sourceMappingURL=Comparator.js.map