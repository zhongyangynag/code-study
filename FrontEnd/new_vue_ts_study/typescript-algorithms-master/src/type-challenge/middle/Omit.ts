//!pass
export type MyExclude<T, U> = T extends U ? never : T;
export type MyOmit<T, U> = {
    [K in MyExclude<keyof T, U>]: T[K];
};

interface Todo {
    title: string;
    description: string;
    completed: boolean;
}

type TodoPreview = MyOmit<Todo, 'description' | 'title'>;

const todo: TodoPreview = {
    completed: false,
};
