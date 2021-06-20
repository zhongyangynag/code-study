/**
 * S = L + S1
 * F = L + n(S1 + S2) + S1
 * F = 2S
 * 2L + 2S1 = L + n(S1 + S2) + S1
 * L = (n-1)(S1 + S2) + S2
 *
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */

var detectCycle = function (head: any) {
    let slowP = head,
        fastP = head; // 都从头节点出发
    while (fastP) {
        // head就是null了，没有入环点，直接返回null
        if (fastP.next == null) return null; // fastP.next为null也说明无环
        slowP = slowP.next; // 慢指针走一步
        fastP = fastP.next.next; // 快指针走两步
        if (slowP == fastP) {
            // 首次相遇
            fastP = head; // 让快指针回到头节点
            while (true) {
                // 开启循环，让快慢指针相遇
                if (slowP == fastP) {
                    // 相遇，地点发生在入环处
                    return slowP; // 返回出指针的位置
                }
                fastP = fastP.next; // 快慢指针都走一步
                slowP = slowP.next;
            }
        }
    }
    return null;
};
