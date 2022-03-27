
/**
 * @author Shahidul Islam
 * @date 2/15/2022
 **/
public class _19_RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int totalNode = 0;
        ListNode cur = head;
        while (cur != null) {
            cur = cur.next;
            totalNode++;
        }
        int nthNodeFromLeft = totalNode - n;

        cur = head;
        for (int i = 0; i < nthNodeFromLeft - 1; i++) {
            if (cur != null)
                cur = cur.next;
        }

        if (nthNodeFromLeft == 0)
            head = cur.next;
        else {
            if (cur != null && cur.next != null)
                cur.next = cur.next.next;
        }
        return head;

    }
}