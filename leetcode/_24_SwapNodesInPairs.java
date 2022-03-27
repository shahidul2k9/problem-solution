
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _24_SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        ListNode sentinelHead = new ListNode(-1, null);
        ListNode ptr = head;
        ListNode tail = sentinelHead;
        ListNode x, y;
        while (ptr != null) {
            x = ptr;
            y = x.next;
            ptr = y != null ? y.next : null;
            x.next = null;
            if (y != null) {
                y.next = null;
                tail.next = y;
                tail = tail.next;
            }
            tail.next = x;
            tail = tail.next;
        }
        return sentinelHead.next;

    }
}
