class PersonObject {
  private _firstname: string = '';

  get firstname(): string {
    return this._firstname;
  };

  set firstname(value: string) {
    if (value.length > 5) {
      this._firstname = value;
    } else {
      console.error('More then 5 char. please');
      this._firstname = '';
    }
  };
};

const person = new PersonObject();
console.log('Firstname: ', person.firstname);

person.firstname = 'Harry';
console.log('Firstname: ', person.firstname);

person.firstname = 'Harman';
console.log('Firstname: ', person.firstname);
