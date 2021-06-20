import { ListNode } from "../../../utils/leetcode/listNode";
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

export default function getIntersectionNode(
    headA: ListNode | null,
    headB: ListNode | null
): ListNode | null {
    if (!headA || !headB) return null;
    let pa: ListNode | null = headA;
    let pb: ListNode | null = headB;
    while (pa !== pb) {
        pa = pa === null ? headA : pa.next;
        pb = pb === null ? headB : pb.next;
    }
    return pa;
}
