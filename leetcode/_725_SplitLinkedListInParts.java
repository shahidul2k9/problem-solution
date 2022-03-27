
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _725_SplitLinkedListInParts {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] partitionList = new ListNode[k];
        int n, np, nr;
        ListNode cur = head;
        n = 0;
        while (cur != null) {
            n++;
            cur = cur.next;
        }
        np = n / k;
        nr = n % k;

        cur = head;
        for (int i = 0; i < k; i++) {
            int tc = np + (nr > 0 ? 1 : 0);
            nr--;
            int c = 0;
            ListNode chunkHead = new ListNode(-1, null);
            ListNode chunkTail = chunkHead;
            while (c < tc) {
                chunkTail.next = cur;
                chunkTail = chunkTail.next;
                cur = cur.next;
                chunkTail.next = null;
                c = c + 1;
            }
            partitionList[i] = chunkHead.next;
        }
        return partitionList;
    }
}
