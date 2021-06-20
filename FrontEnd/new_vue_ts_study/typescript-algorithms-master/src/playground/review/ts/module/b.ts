let a = 100;
a++;
export function f() {
    console.log(a);
}

a++;

setTimeout(() => {
    a++;
}, 1000);
