import { AvlTree } from "../AvlTree";

test("test insert", () => {
    let avltree = new AvlTree();
    avltree.insert(null);
    avltree.insert(7);
    avltree.insert(4);
    avltree.insert(9);
    avltree.insert(8);
    avltree.insert(2);
    avltree.insert(1);
    avltree = new AvlTree();
    avltree.insert(7);
    avltree.insert(4);
    avltree.insert(9);
    avltree.insert(11);
    avltree.insert(10);
    avltree.insert(7);
    avltree.insert(5);
    avltree.insert(9);
    avltree.insert(4);
    avltree.insert(3);
    avltree.insert(12);
    avltree.insert(13);
    avltree.insert(14);
    avltree = new AvlTree();
    avltree.insert(7);
    avltree.insert(5);
    avltree.insert(9);
    avltree.insert(3);
    avltree.insert(4);
    avltree = new AvlTree();
    avltree.insert(4);
    avltree.insert(3);
    avltree.insert(5);
    avltree.insert(7);
    avltree.insert(9);
    avltree = new AvlTree();
    avltree.insert(4);
    avltree.insert(3);
    avltree.insert(5);
    avltree.insert(9);
    avltree.insert(7);
    avltree = new AvlTree();
    avltree.insert(4);
    avltree.insert(8);
    avltree.insert(2);
    avltree.insert(5);
    avltree.insert(7);
    avltree.insert(6);
    avltree = new AvlTree();
    avltree.insert(9);
    avltree.insert(7);
    avltree.insert(11);
    avltree.insert(5);
    avltree.insert(6);
});

test("test remove", () => {
    let avltree = new AvlTree();
    avltree.remove(null);
    avltree.remove(9);
    avltree.insert(7);
    avltree.remove(12);
    avltree.remove(7);
    avltree.remove(11);
    avltree = new AvlTree();
    avltree.insert(4);
    avltree.insert(9);
    avltree.insert(2);
    avltree.insert(5);
    avltree.insert(8);
    avltree.insert(10);
    expect(avltree.Root.getHeight()).toEqual(2);
    expect(avltree.getAscSeq().toString()).toEqual("2,4,5,8,9,10");
    avltree.remove(9);
    expect(avltree.getAscSeq().toString()).toEqual("2,4,5,8,10");
    avltree.remove(4);
    expect(avltree.getAscSeq().toString()).toEqual("2,5,8,10");
});