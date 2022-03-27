
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _2130_MaximumTwinSumOfALinkedList {
    private ListNode rightHead;

    public int pairSum(ListNode head) {
        int n = 0;
        ListNode cur = head;
        while (cur != null) {
            cur = cur.next;
            n++;
        }
        return maxSum(head, n / 2);
    }

    private int maxSum(ListNode head, int h) {
        if (h > 0) {
            int mx = maxSum(head.next, h - 1);
            mx = Math.max(mx, head.val + rightHead.val);
            rightHead = rightHead.next;
            return mx;
        } else {
            rightHead = head;
            return Integer.MIN_VALUE;
        }
    }
}
