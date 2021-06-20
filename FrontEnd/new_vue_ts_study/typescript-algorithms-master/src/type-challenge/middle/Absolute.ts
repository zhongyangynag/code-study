type Test = -100;
type Test1 = 100;

export type Absolute<
    T extends number | string | bigint
> = `${T}` extends `-${infer R}` ? R : `${T}`;

type Result = Absolute<Test>; // expected to be "100"
type Result1 = Absolute<Test1>; // expected to be "100"
