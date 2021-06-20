// Inheritance
class Person {
  public constructor(public name: string, public username: string) {};
  private type: string;
  protected age: number;

  public printAge(age: number = 0) {
    this.age = age;
    this.setType('Geek');
    return this.age;
  };

  private setType(type: string) {
    this.type = type;
    console.log(this.type);
  };
};

class Harry extends Person {  
  public constructor(username: string, age: number) {
    super('Harman Manchanda', username);
    this.age = age;
  };
};

const userPerson = new Person('Harry Manchanda', 'IamManchanda');
console.log( userPerson );
console.log( userPerson.name );
console.log( userPerson.username );
console.log( userPerson.printAge(24) );

console.log('------------------------------');

const userHarry = new Harry('IamManchanda', 25);
console.log( userHarry );
console.log( userHarry.name );
console.log( userHarry.username );
console.log( userHarry.printAge(26) );
