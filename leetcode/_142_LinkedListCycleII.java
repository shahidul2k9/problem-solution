
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _142_LinkedListCycleII {
    public ListNode detectCycle(ListNode head) {
        ListNode slow, fast;
        slow = fast = head;
        slow = (slow != null ? slow.next : null);
        fast = (fast != null && fast.next != null ? fast.next.next : null);
        while (slow != fast && fast != null) {
            slow = slow.next;
            fast = fast.next != null ? fast.next.next : null;
        }
        if (fast == null) {
            return null;
        }
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;

    }
}
