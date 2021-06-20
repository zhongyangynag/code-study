import { StringToTuple } from './StrLength';

type StringToUnion<T extends string> = StringToTuple<T>[number];

type Test = '123';
type Result = StringToUnion<Test>; // expected to be "1" | "2" | "3"
