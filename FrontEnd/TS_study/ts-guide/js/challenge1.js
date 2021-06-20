"use strict";
var bankAccount;
bankAccount = {
    money: 2000,
    deposit: function (value) {
        this.money += value;
    },
};
var myself;
myself = {
    name: "Harry Manchanda",
    bankAccount: bankAccount,
    hobbies: ["Cricket", "Coding"],
};
myself.bankAccount.deposit(3000);
console.log(myself);
//# sourceMappingURL=challenge1.js.map