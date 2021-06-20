"use strict";
var PersonObject = /** @class */ (function () {
    function PersonObject() {
        this._firstname = '';
    }
    Object.defineProperty(PersonObject.prototype, "firstname", {
        get: function () {
            return this._firstname;
        },
        set: function (value) {
            if (value.length > 5) {
                this._firstname = value;
            }
            else {
                console.error('More then 5 char. please');
                this._firstname = '';
            }
        },
        enumerable: true,
        configurable: true
    });
    ;
    ;
    return PersonObject;
}());
;
var person = new PersonObject();
console.log('Firstname: ', person.firstname);
person.firstname = 'Harry';
console.log('Firstname: ', person.firstname);
person.firstname = 'Harman';
console.log('Firstname: ', person.firstname);
//# sourceMappingURL=challenge4.js.map