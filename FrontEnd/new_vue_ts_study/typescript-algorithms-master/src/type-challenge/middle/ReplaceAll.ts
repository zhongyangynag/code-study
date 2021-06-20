export type ReplaceAll<
    T extends string,
    D extends string,
    P extends string
> = T extends `${infer L}${D}${infer R}` ? `${L}${P}${ReplaceAll<R, D, P>}` : T;

type str = 'am i am faker, and i am a man.';
type strp = ReplaceAll<ReplaceAll<str, 'i', 'he'>, 'am', 'is'>;
