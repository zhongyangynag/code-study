"use strict";
// Private Constructor
var OnlyOne = /** @class */ (function () {
    function OnlyOne(name) {
        this.name = name;
    }
    ;
    OnlyOne.getInstance = function () {
        if (!OnlyOne.instance) {
            OnlyOne.instance = new OnlyOne('The Only One');
        }
        return OnlyOne.instance;
    };
    ;
    return OnlyOne;
}());
;
// const wrong = new OnlyOne('The Only One');
var right = OnlyOne.getInstance();
console.log(right);
//# sourceMappingURL=script6.js.map