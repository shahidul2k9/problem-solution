
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _25_ReverseNodesInKGroup {
    private ListNode nextHead;

    public ListNode reverseKGroup(ListNode head, int k) {
        int n = 0;
        ListNode sentinelHead = new ListNode(-1, null);
        ListNode cur, tail;
        cur = head;
        while (cur != null) {
            n++;
            cur = cur.next;
        }

        int cn = 0;
        tail = sentinelHead;
        nextHead = head;
        while (n - cn >= k) {
            ListNode rev = reverseTopKNodes(nextHead, k);
            tail.next = rev;
            while (tail.next != null)
                tail = tail.next;
            cn = cn + k;
        }
        tail.next = nextHead;
        return sentinelHead.next;
    }

    private ListNode reverseTopKNodes(ListNode head, int k) {
        if (k == 0)
            return null;
        else if (k == 1) {
            nextHead = head.next;
            head.next = null;
            return head;
        } else {
            ListNode rev = reverseTopKNodes(head.next, k - 1);
            head.next = null;
            rev.next = head;
            return rev;
        }
    }

}
