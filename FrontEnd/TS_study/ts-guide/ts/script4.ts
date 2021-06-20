// Static Properties & Methods
class Helpers {
  static PI: number = 3.14;
  static calculateCircumference(diameter: number) {
    return this.PI * diameter;
  };
};

console.log( Helpers.calculateCircumference(8) );
