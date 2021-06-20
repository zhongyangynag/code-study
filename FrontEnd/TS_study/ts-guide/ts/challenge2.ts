class Car {
  public constructor(
    public name: string, 
    public acceleration: number = 0,
  ) {};

  public honk() {
    console.log('Tooooot!');
  };

  public accelerate(speed: number) {
    this.acceleration += speed;
  };
};

const carObject = new Car('BMW', 2);
carObject.honk();

console.log(carObject.acceleration);
carObject.accelerate(20);
console.log(carObject.acceleration);
