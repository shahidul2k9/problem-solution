
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _2095_DeleteTheMiddleNodeOfALinkedList {
    public ListNode deleteMiddle(ListNode head) {
        ListNode slow, fast, slowPrev;
        slow = fast = slowPrev = head;

        while (fast != null && fast.next != null) {
            slowPrev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        if (slow == head) {
            return null;
        } else {
            slowPrev.next = slow.next;
        }
        return head;
    }
}
