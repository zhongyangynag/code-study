export type StringToTuple<T extends string> = T extends `${infer F}${infer R}`
    ? F extends ''
        ? []
        : [F, ...StringToTuple<R>]
    : [];

export type StrLength<T extends string> = StringToTuple<T>['length'];

type L = StrLength<'name'>;
