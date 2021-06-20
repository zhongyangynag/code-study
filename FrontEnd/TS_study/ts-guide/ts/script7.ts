namespace myMath {
  export namespace Rectangle {
    export const calculateRectangle = (width: number, height: number = width): number => {
      return width * height;
    };
  };

  export namespace Circle {
    export const calculateCircumference = (diameter: number): number => {
      const PI = 3.14;
      return diameter * PI;
    };
  };
};

import RectangleMath = myMath.Rectangle;
import CircleMath = myMath.Circle;

console.log( RectangleMath.calculateRectangle(10) );
console.log( RectangleMath.calculateRectangle(10, 20) );
console.log( CircleMath.calculateCircumference(10) );
