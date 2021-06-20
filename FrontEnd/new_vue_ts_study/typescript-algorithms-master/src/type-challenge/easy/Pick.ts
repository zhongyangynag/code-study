//! Pass
type Include<T, U> = T extends U ? T : never;

export type MyPick<T, U> = {
    [K in Include<keyof T, U>]: T[K];
};

interface Todo {
    title: string;
    description: string;
    completed: boolean;
}

type TodoPreview = MyPick<Todo, 'title' | 'completed'>;

const todo: TodoPreview = {
    title: 'Clean room',
    completed: false,
    // description: '', error
};
