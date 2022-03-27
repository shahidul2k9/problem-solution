
/**
 * @author Shahidul Islam
 * @date 2/14/2022
 **/
public class _61_RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        int n = 0;
        ListNode cur = head;
        while (cur != null) {
            n++;
            cur = cur.next;
        }

        k = n == 0? 0 : k % n;
        if (k == 0) {
            return head;
        } else {
            cur = head;
            for (int i = 0; i < n - k - 1; i++) {
                cur = cur.next;
            }
            ListNode newHead = cur.next;
            cur.next = null;
            cur = newHead;
            while (cur.next != null) {
                cur = cur.next;
            }
            cur.next = head;
            return newHead;
        }
    }
}
