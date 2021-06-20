type AlphaMap = {
    a: 'A';
    b: 'B';
    c: 'C';
    d: 'D';
    e: 'E';
    f: 'F';
    g: 'G';
    h: 'H';
    // ...more alphas
};

type Alphas = keyof AlphaMap;

export type Capitalize<T extends string> = T extends `${infer F}${infer R}`
    ? F extends Alphas
        ? `${AlphaMap[F]}${R}`
        : T
    : T;

type Str = 'abc def hij';
type CaStr = Capitalize<Str>;
