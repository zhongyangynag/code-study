// Get an Object that is the difference between O & O1
export type Diff<N1, N2> = {
    [K in
        | Exclude<keyof N1, keyof N2>
        | Exclude<keyof N2, keyof N1>]: K extends keyof N1
        ? N1[K]
        : K extends keyof N2
        ? N2[K]
        : never;
};

type Foo = {
    name: string;
    age: string;
    address: string;
};
type Bar = {
    name: string;
    age: number;
    gender: number;
};

export type diff = Diff<Foo, Bar>;
