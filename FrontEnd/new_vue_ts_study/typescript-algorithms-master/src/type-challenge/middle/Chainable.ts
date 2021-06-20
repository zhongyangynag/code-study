// interface Config {
//     [propName: string]: any
// }

// export type Chainable = Config & {
//     option: (key: string, value: any) => Chainable;
//     get: () => Chainable
// }

export type Chainable<Result = {}> = {
    option<K extends string, V>(
        key: K,
        value: V
    ): Chainable<Result & { [key in K]: V }>;
    get(): Result;
};

const config: Chainable<> = {
    option(key: string, value: any) {
        this[key] = value;
        return this;
    },
    get() {
        return this;
    },
};

const result = config
    .option('foo', 123)
    .option('name', 'type-challenges')
    .option('bar', { value: 'Hello World' })
    .get();

console.log(result);

// 期望 result 的类型是：
interface Result {
    foo: number;
    name: string;
    bar: {
        value: string;
    };
}
