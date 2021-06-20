interface Man {
    name: string;
    funk: () => {};
}

class Bro {
    readonly name: string;
    constructor() {
        this.name = 'bro';
    }
    funk() {
        return {};
    }
}

const bro: Bro = {
    name: '',
    funk() {
        return {};
    },
};

const sis: Man = {
    name: 'sis',
};

interface CallMeWithNewToGetString {
    new (): string;
}

// 使用
function Foo() {
    return '';
}
const bar: CallMeWithNewToGetString = new Foo(); // bar 被推断为 string 类型
