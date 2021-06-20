export type Replace<
    T extends string,
    D extends string,
    P extends string
> = T extends `${infer L}${D}${infer R}` ? `${L}${P}${R}` : T;

type str = 'am i am faker';
type strp = Replace<str, 'am', 'is'>;
