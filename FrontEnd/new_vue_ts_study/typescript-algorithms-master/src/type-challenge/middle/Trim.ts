// TODO
// !pass
type Space = ' ' | '\t' | '\n';

export type TrimLeft<T extends string> = T extends `${Space}${infer R}`
    ? TrimLeft<R>
    : T;

export type TrimRight<T extends string> = T extends `${infer L}${Space}`
    ? TrimRight<L>
    : T;

export type Trim<T extends string> = TrimLeft<TrimRight<T>>;

type str = ' asscd ';
type ts = Trim<str>;
