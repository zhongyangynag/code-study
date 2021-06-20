"use strict";
var myMath;
(function (myMath) {
    var Rectangle;
    (function (Rectangle) {
        Rectangle.calculateRectangle = function (width, height) {
            if (height === void 0) { height = width; }
            return width * height;
        };
    })(Rectangle = myMath.Rectangle || (myMath.Rectangle = {}));
    ;
    var Circle;
    (function (Circle) {
        Circle.calculateCircumference = function (diameter) {
            var PI = 3.14;
            return diameter * PI;
        };
    })(Circle = myMath.Circle || (myMath.Circle = {}));
    ;
})(myMath || (myMath = {}));
;
var RectangleMath = myMath.Rectangle;
var CircleMath = myMath.Circle;
console.log(RectangleMath.calculateRectangle(10));
console.log(RectangleMath.calculateRectangle(10, 20));
console.log(CircleMath.calculateCircumference(10));
//# sourceMappingURL=script7.js.map