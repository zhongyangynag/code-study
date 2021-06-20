//!pass
// TODO
type Space = ' ' | '\t' | '\n';
type TrimLeft<T extends string> = T extends `${infer S}${infer R}` // 提取第一个字符
    ? S extends Space
        ? TrimLeft<R>
        : T
    : never;

type str = ' 123';

type ts = TrimLeft<str>;

type Extract_<T extends string> = T extends `${infer L}_${infer R}`
    ? `${L}${R}`
    : never;

type StrWith_ = 'L_R';
type StrWithout_ = Extract_<StrWith_>;

// KNOWN${UNKNOWN(dynamic)}
// 模板字符串也算是一种类型，一种有已确定部分和未确定(动态)部分的类型。
// 模板字符串推断可以提取出某个特定的字符，还可以(递归)提取第一个字符
