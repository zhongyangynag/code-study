"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = Object.setPrototypeOf ||
        ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
        function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
// Inheritance
var Person = /** @class */ (function () {
    function Person(name, username) {
        this.name = name;
        this.username = username;
    }
    ;
    Person.prototype.printAge = function (age) {
        if (age === void 0) { age = 0; }
        this.age = age;
        this.setType('Geek');
        return this.age;
    };
    ;
    Person.prototype.setType = function (type) {
        this.type = type;
        console.log(this.type);
    };
    ;
    return Person;
}());
;
var Harry = /** @class */ (function (_super) {
    __extends(Harry, _super);
    function Harry(username, age) {
        var _this = _super.call(this, 'Harman Manchanda', username) || this;
        _this.age = age;
        return _this;
    }
    ;
    return Harry;
}(Person));
;
var userPerson = new Person('Harry Manchanda', 'IamManchanda');
console.log(userPerson);
console.log(userPerson.name);
console.log(userPerson.username);
console.log(userPerson.printAge(24));
console.log('------------------------------');
var userHarry = new Harry('IamManchanda', 25);
console.log(userHarry);
console.log(userHarry.name);
console.log(userHarry.username);
console.log(userHarry.printAge(26));
//# sourceMappingURL=script2.js.map