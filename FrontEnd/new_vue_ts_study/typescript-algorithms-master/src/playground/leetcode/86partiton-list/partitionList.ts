import buildList from "../../../utils/leetcode/listBuilder.ts";
/**
 * Definition for singly-linked list.
 */
class ListNode {
    val: number;
    next: ListNode | null;
    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

function partition(head: ListNode | null, x: number): ListNode | null {
    if (!head) return head;
    let before = new ListNode(0);
    const beforeHead = before;
    let after = new ListNode(0);
    const afterHead = after;

    while (head) {
        if (head.val < x) {
            before.next = head;
            before = before.next;
        } else {
            after.next = head;
            after = after.next;
        }
        head = head.next;
    }
    before.next = afterHead.next;
    after.next = null;
    return beforeHead.next;
}

let head = buildList([1, 4, 3, 2, 5, 2]);

let res = partition(head, 3);

let i = 10;
while (res && i > 0) {
    i--;
    console.log(res.val);
    res = res.next;
}
