//!pass
type Length<T extends Array<any>> = T['length'];

type arr = [1, 2, 3];

type ArrLen = Length<arr>;

type str = Pick<{ a: '1' }, 'a'>;
