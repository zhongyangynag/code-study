//! Pass
// type Flatten<T> = T extends readonly any[] ? T[number] : never;
type Flatten<T extends readonly any[]> = T[number];

type TupleToObject<T extends readonly any[]> = {
    [K in Flatten<T>]: K;
};

// type TupleToObject<T extends readonly any[]> = {
//     [P in T[number]]: P;
// };

const tuple = ['tesla', 'model 3', 'model X', 'model Y'] as const;

const result: TupleToObject<typeof tuple> = {
    tesla: 'tesla',
    'model 3': 'model 3',
    'model X': 'model X',
    'model Y': 'model Y',
    // b: 'a', error
};

type arrType = Flatten<typeof tuple>;
