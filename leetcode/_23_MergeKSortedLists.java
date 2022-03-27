
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _23_MergeKSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode sentinelHead = new ListNode(Integer.MIN_VALUE, null);
        ListNode x, y, com;
        for (int i = 0; i < lists.length; i++) {
            x = lists[i];
            y = sentinelHead.next;
            com = sentinelHead;
            while (x != null && y != null) {
                if (x.val < y.val) {
                    com.next = x;
                    x = x.next;
                } else {
                    com.next = y;
                    y = y.next;
                }
                com = com.next;
            }
            if (x == null) {
                com.next = y;
            } else {
                com.next = x;
            }
        }
        return sentinelHead.next;

    }
}
