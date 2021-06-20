"use strict";
var Car = /** @class */ (function () {
    function Car(name, acceleration) {
        if (acceleration === void 0) { acceleration = 0; }
        this.name = name;
        this.acceleration = acceleration;
    }
    ;
    Car.prototype.honk = function () {
        console.log('Tooooot!');
    };
    ;
    Car.prototype.accelerate = function (speed) {
        this.acceleration += speed;
    };
    ;
    return Car;
}());
;
var carObject = new Car('BMW', 2);
carObject.honk();
console.log(carObject.acceleration);
carObject.accelerate(20);
console.log(carObject.acceleration);
//# sourceMappingURL=challenge2.js.map