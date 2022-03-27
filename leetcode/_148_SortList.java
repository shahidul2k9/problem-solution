
/**
 * @author Shahidul Islam
 * @date 2/22/2022
 **/
public class _148_SortList {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        } else {
            ListNode midPrev = findMidPrev(head);
            ListNode mid = midPrev.next;
            midPrev.next = null;
            ListNode lef = sortList(head);
            ListNode right = sortList(mid.next);
            mid.next = null;
            ListNode halfway = mergeSortedList(lef, mid);
            return mergeSortedList(halfway, right);
        }
    }

    private ListNode mergeSortedList(ListNode left, ListNode right) {
        ListNode sentinelHead = new ListNode(0, null);
        ListNode cur = sentinelHead;
        while (left != null && right != null) {
            if (left.val < right.val) {
                cur.next = left;
                left = left.next;
            } else {
                cur.next = right;
                right = right.next;
            }
            cur = cur.next;
        }
        cur.next = left != null ? left : right;
        return sentinelHead.next;
    }

    private ListNode findMidPrev(ListNode head) {
        ListNode slow, fast, prev;
        prev = slow = fast = head;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        return prev;
    }
}
