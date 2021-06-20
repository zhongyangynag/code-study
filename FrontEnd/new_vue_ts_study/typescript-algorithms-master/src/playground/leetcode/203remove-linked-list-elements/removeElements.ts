import { ListNode } from "../../../utils/leetcode/listNode.ts";
import buildList from "../../../utils/leetcode/listBuilder.ts";
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeElements(head: ListNode | null, val: number): ListNode | null {
    let preHead = new ListNode(-1, head);
    let pre: ListNode | null = preHead;
    while (pre && pre.next) {
        let nxt = pre.next;
        if (nxt.val === val) {
            pre.next = pre.next.next;
        } else {
            pre = pre.next;
        }
    }
    return preHead.next;
}

// function removeElements2(head: ListNode | null, val: number): ListNode | null {}

// function dfs(head: ListNode | null, val: number): ListNode | null {
//     if (head === null) return head;
//     if (head.val === val) dfs(head.next, val);
//     head.next = dfs(head.next, val);
//     return head;
// }

let list = buildList([3, 1, 2, 3, 3, 4, 3]);
let head = removeElements(list, 3);
while (head) {
    console.log(head.val);
    head = head.next;
}
