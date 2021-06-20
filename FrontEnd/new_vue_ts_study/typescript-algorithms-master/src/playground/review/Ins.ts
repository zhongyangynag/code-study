namespace T1 {
    interface A {
        name: string;
    }

    type B = {
        age: number;
    };

    type T1 = A & B;

    let t: T1 = {
        name: '',
        age: 1,
    };

    type T2 = string & number;
    type T2 = boolean & string;
    type T2 = undefined & string;
    type T2 = null & string;
    type T2 = undefined & null;
    type T2 = object & string;
    type T2 = string & Symbol;
    type T2 = object & Symbol;

    type T3 = any & T1;
    type T3 = any & string;
    type T3 = any & never;
    type T3 = any & string;

    type T3 = unknown & string;
    type T3 = unknown & never;
    type T3 = unknown & void;

    type T4 = [number, string] & Array<number>;
    type T5 = (name: any) => number & ((name: string) => number);
    function ff1(name: string): number;
    function ff1(name: number): number;
    function ff1(name: string | number): number {
        if (typeof name === 'string') {
            console.log(name);
        }

        if (typeof name === 'number') {
            console.log(name);
        }
        return 1;
    }
    let f1: T5 = ff1;
}
