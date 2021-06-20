//!pass
type IncludesHelper<T, U> = T extends U ? true : never;
type Includes<T extends any[], U> = IncludesHelper<T[number], U> extends never
    ? false
    : true;

type isPillarMen = Includes<['Kars', 'Esidisi', 'Wamuu', 'Santana'], 'Dio'>;
// expected to be `false`
type isFruit = Includes<['Apple', 'Banana', 'Orange', 'Water'], 'Water'>;
// expected to be `true`
