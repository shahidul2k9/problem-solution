
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _82_RemoveDuplicatesFromSortedListII {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode left, right;
        ListNode sentinel = new ListNode(Integer.MAX_VALUE, null);
        sentinel.next = head;
        left = sentinel;
        right = left.next;
        while (right != null) {
            while (right.next != null && right.val == right.next.val) {
                right = right.next;
            }
            if (left.next != right) {
                left.next = right.next;
            } else {
                left = right;
            }
            right = right.next;
        }
        return sentinel.next;

    }
}
