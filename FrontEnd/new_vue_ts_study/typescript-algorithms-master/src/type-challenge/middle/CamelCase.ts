import { KebabCase } from './KebabCase';

export type CamelCase<
    T extends string
> = KebabCase<T> extends `${infer F}${infer R}` ? `${Lowercase<F>}${R}` : '';

type Str = 'abc-def-hij';
type CaStr = CamelCase<Str>;

// for-bar-baz -> for-Bar-Baz
