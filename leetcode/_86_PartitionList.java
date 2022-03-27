
/**
 * @author Shahidul Islam
 * @date 2/19/2022
 **/
public class _86_PartitionList {
    public ListNode partition(ListNode head, int x) {
        if (head == null)
            return head;
        ListNode low = new ListNode(-1, null);
        ListNode high = new ListNode(-1, null);
        ListNode curLow, curHigh, cur;
        curLow = low;
        curHigh = high;
        cur = head;
        while (cur != null) {
            if (cur.val < x) {
                curLow.next = cur;
                curLow = cur;
            } else {
                curHigh.next = cur;
                curHigh = cur;
            }
            cur = cur.next;
            curLow.next = null;
            curHigh.next = null;
        }
        curLow.next = high.next;
        return low.next;

    }
}
