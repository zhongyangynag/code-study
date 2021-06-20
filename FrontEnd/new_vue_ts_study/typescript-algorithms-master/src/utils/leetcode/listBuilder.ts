import { ListNode } from "./listNode.ts";

export function printList(head: ListNode | null): void {
    while (head) {
        console.log(head.val);
        head = head.next;
    }
}

export default function buildList(input: Array<number>): ListNode | null {
    let list = new ListNode(0);
    let head = list;
    input.forEach((item) => {
        list.next = new ListNode(item);
        list = list.next;
    });
    return head.next;
}
