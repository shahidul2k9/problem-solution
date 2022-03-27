
/**
 * @author Shahidul Islam
 * @date 2/15/2022
 **/
public class _1721_SwappingNodesInALinkedList {
    public ListNode swapNodes(ListNode head, int k) {
        int n = 0;
        ListNode cur = head;
        while (cur != null) {
            n++;
            cur = cur.next;
        }
        ListNode a = null;
        ListNode b = null;
        cur = head;
        for (int i = 1; i <= n; i++) {
            if (i == k) {
                a = cur;
            }
            if (i == n - k + 1) {
                b = cur;
            }
            cur = cur.next;
        }

        int tmpVal = a.val;
        a.val = b.val;
        b.val = tmpVal;

        return head;
    }
}
