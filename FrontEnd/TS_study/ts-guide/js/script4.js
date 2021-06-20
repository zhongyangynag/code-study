"use strict";
// Static Properties & Methods
var Helpers = /** @class */ (function () {
    function Helpers() {
    }
    Helpers.calculateCircumference = function (diameter) {
        return this.PI * diameter;
    };
    ;
    Helpers.PI = 3.14;
    return Helpers;
}());
;
console.log(Helpers.calculateCircumference(8));
//# sourceMappingURL=script4.js.map