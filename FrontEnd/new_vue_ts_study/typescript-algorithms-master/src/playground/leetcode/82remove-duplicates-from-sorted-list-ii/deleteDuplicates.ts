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

export default function deleteDuplicates(
    head: ListNode | null
): ListNode | null {
    let preHead = new ListNode(Number.MAX_VALUE, head);
    let pre = preHead;
    let cur = preHead.next;
    let isRepeat = false;
    while (cur !== null) {
        let nxt = cur.next;
        if (nxt && cur.val === nxt.val) {
            pre.next = nxt;
            cur = cur.next;
            isRepeat = true;
        } else {
            if (isRepeat) {
                pre.next = nxt;
                cur = pre.next;
                isRepeat = false;
            }
            cur = cur.next;
            pre = pre.next;
        }
    }
    return preHead.next;
}

//    1， 2， 3， 3， 3
//      pre cur nxt
//    1， 2， 3，
//               3， 3
//              cur nxt
//              pre

let list: ListNode | null = buildList([1, 1, 1, 2, 2, 3, 4, 4]);
list = deleteDuplicates(list);
while (list !== null) {
    console.log(list.val);
    list = list.next;
}
