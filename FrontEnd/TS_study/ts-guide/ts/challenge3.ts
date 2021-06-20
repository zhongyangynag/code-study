abstract class BaseObject {
  public width: number = 0;
  public length: number = 0;
};

class Rectangle extends BaseObject {
  public calculateSize() {
    return this.width * this.length;
  };
};

const rect = new Rectangle();
rect.width = 5;
rect.length = 10;
console.log( rect.calculateSize() );
