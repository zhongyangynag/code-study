// Private Constructor
class OnlyOne {
  private constructor(public readonly name: string) {};
  private static instance: OnlyOne;
  
  public static getInstance() {
    if (!OnlyOne.instance) { OnlyOne.instance = new OnlyOne('The Only One'); }
    return OnlyOne.instance;
  };
};

// const wrong = new OnlyOne('The Only One');
const right = OnlyOne.getInstance();
console.log(right);
