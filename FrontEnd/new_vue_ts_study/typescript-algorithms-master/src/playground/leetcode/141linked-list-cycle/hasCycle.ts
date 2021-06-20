import { ListNode } from '../../../utils/leetcode/listNode';

export default function hasCycle(head: ListNode | null) {
    let mark = Number.MAX_VALUE;
    while (head) {
        if (head.val === mark) return true;
        head.val = mark;
        head = head.next;
    }
    return false;
}

export function hasCycleDoublePtr(head: ListNode | null) {
    if (!head || !head.next) return false;
    let fastPtr: ListNode | null = head.next;
    let slowPtr: ListNode | null = head;
    while (fastPtr !== slowPtr) {
        if (fastPtr === null || fastPtr.next === null) return false;
        fastPtr = fastPtr.next.next;
        slowPtr = slowPtr!.next;
    }
    return true;
}
