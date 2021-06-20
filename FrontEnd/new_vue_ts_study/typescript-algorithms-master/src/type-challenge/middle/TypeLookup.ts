type LookUp<U, T> = Extract<U, { type: T }>;

interface Cat {
    type: 'cat';
    breeds: 'Abyssinian' | 'Shorthair' | 'Curl' | 'Bengal';
}

interface Dog {
    type: 'dog';
    breeds: 'Hound' | 'Brittany' | 'Bulldog' | 'Boxer';
    color: 'brown' | 'white' | 'black';
}

type MyDog = LookUp<Cat | Dog, 'dog'>; // expected to be `Dog`

type Foo = [first: number, second?: string, ...rest: any[]];

function A(first: number, second?: string, ...rest: any[]) {
    console.log(rest);
}

A(1, '2', 1, 2, 3);

function tail<T extends any[]>(arr: readonly [any, ...T]) {
    const [_ignored, ...rest] = arr;
    return rest;
}

const myTuple = [1, 2, 3, 4] as const;
const r1 = tail(myTuple);
//    ^ = const r1: [2, 3, 4]
