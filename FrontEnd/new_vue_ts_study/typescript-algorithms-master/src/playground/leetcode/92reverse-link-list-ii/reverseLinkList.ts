import buildList, { printList } from "../../../utils/leetcode/listBuilder.ts";

//  Definition for singly-linked list.
class ListNode {
    val: number;
    next: ListNode | null;
    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

function reverseBetween(
    head: ListNode | null,
    m: number,
    n: number
): ListNode | null {
    let cur = head;
    let pre = null;
    let idx = 1;
    let l: ListNode | null = pre;
    let r: ListNode | null = cur;
    while (cur) {
        if (idx <= m) {
            l = pre;
            r = cur;
            pre = cur;
            cur = cur.next;
            idx++;
            continue;
        }
        let nxt: ListNode | null = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
        idx++;
        if (idx > n) {
            if (l) {
                l.next = pre;
            } else {
                head = pre;
            }
            r && (r.next = cur);

            return head;
        }
    }
    return head;
}

function reverse(head: ListNode | null): ListNode | null {
    let pre = null;

    while (head) {
        let nxt: ListNode | null = head.next;
        head.next = pre;
        pre = head;
        if (!nxt) {
            return head;
        }
        head = nxt;
    }
    return head;
}
let list = buildList([1, 2, 3, 4, 5]);
printList(list);

printList(reverseBetween(list, 2, 4));
