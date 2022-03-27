
class _2_AddTwoNumber {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode p = l1;
        ListNode q = l2;

        int s = 0;
        ListNode head = null;
        ListNode ptr = null;
        while (p != null || q != null){
            if (p != null){
                s += p.val;
                p = p.next;
            }
            if (q != null){
                s += q.val;
                q = q.next;
            }
            if (head == null){
                head = new ListNode(s % 10);
                ptr = head;
            }else {
                ptr.next = new ListNode(s %10);
                ptr = ptr.next;
            }
            s /= 10;
        }

        if (s > 0){
            ptr.next = new ListNode(s);
        }
        return head;
    }
}