export type TupleToUnion<T extends any[]> = T[number];

namespace TTU {
    type Arr = ['1', '2', '3'];
    let a: TupleToUnion<Arr>;
    // expected to be '1' | '2' | '3'
}
