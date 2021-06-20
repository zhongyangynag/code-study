//!pass
export type Flatten<T extends any[]> = T extends [infer F, ...infer R]
    ? F extends any[]
        ? Flatten<[...F, ...R]>
        : [F, ...Flatten<R>]
    : [];

type arr = [1, ...[]];
type nvr = never;
type invalid = [1, ...never];
type invalid1 = never & 1;
type invalid2 = `${nvr}`;
type valid = never | 1;

type Keys = 'option1' | 'option2';
type Flags = { [K in Keys]: never };

type valid2 = {
    a: never;
    b: string;
};

type Tuple1 = [1, 2, 3, [4], [5, 6]];
type ExpandedTunple = Flatten<Tuple1>;
