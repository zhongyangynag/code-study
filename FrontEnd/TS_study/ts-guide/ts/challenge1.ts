type BankAccountType = {
  money: number,
  deposit: (value: number) => void,
};

let bankAccount: BankAccountType;
bankAccount = {
  money: 2000,
  deposit(value) {
      this.money += value;
  },
};

let myself: {
  name: string,
  bankAccount: BankAccountType,
  hobbies: string[],
};
myself = {
  name: "Harry Manchanda",
  bankAccount,
  hobbies: ["Cricket", "Coding"],
};

myself.bankAccount.deposit(3000);
console.log(myself);

