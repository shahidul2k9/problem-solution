
/**
 * @author Shahidul Islam
 * @date 2/19/2022
 **/
public class _92_ReverseLinkedListII {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode begin, middle, beginCur, middleCur, cur;
        begin = beginCur = new ListNode(0, null);
        middle = middleCur = new ListNode(0, null);

        int n = 1;
        cur = head;
        while (n <= right && cur != null) {
            ListNode nextCur = cur.next;
            if (n < left) {
                beginCur.next = cur;
                beginCur = beginCur.next;
            } else if (n <= right) {
                cur.next = middleCur;
                middleCur = cur;
            }
            cur = nextCur;
            n++;
        }
        beginCur.next = middleCur;
        while (middleCur.next != middle) {
            middleCur = middleCur.next;
        }
        middleCur.next = cur;
        return begin.next;
    }
}
