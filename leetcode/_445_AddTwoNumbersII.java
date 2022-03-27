
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _445_AddTwoNumbersII {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int m = 0;
        int n = 0;
        ListNode cur;
        cur = l1;
        while (cur != null) {
            m++;
            cur = cur.next;
        }

        cur = l2;
        while (cur != null) {
            n++;
            cur = cur.next;
        }
        if (m < n) {
            cur = l1;
            l1 = l2;
            l2 = cur;
            int tmp = m;
            m = n;
            n = tmp;
        }

        int c = sum(l1, l2, m, n);
        if (c == 0) {
            return l1;
        } else {
            return new ListNode(c, l1);
        }
    }

    private int sum(ListNode a, ListNode b, int m, int n) {
        if (a == null) {
            return 0;
        } else {
            int s;
            if (m == n) {
                s = sum(a.next, b.next, m - 1, n - 1) + a.val + b.val;
            } else {
                s = sum(a.next, b, m - 1, n) + a.val;
            }
            a.val = s / 10;
            return s % 10;
        }
    }
}
