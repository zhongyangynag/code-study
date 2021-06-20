//!pass
type Await<T> = T extends Promise<infer C> ? C : never;

type awa = Await<Promise<string>>;
