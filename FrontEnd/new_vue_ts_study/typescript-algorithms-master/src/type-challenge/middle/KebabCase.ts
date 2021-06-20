export type Delta = '-';

export type Split<T extends string, D extends string> = T extends ''
    ? []
    : T extends `${infer L}${D}${infer R}`
    ? L extends ''
        ? []
        : [L, ...Split<R, D>]
    : [T];

export type Join<T extends any[], D extends string> = T extends [
    infer F,
    ...infer R
]
    ? F extends string
        ? R[0] extends string
            ? `${Capitalize<F>}${D}${Join<R, D>}`
            : `${Capitalize<F>}`
        : ''
    : '';

export type KebabCase<T extends string> = Join<Split<T, Delta>, Delta>;

type Str = 'abc-def-hij';
type kebabaStr = KebabCase<Str>;

// for-bar-baz -> For-Bar-Baz
