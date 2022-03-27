/**
 * @author Shahidul Islam
 * @date 1/25/2022
 **/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class _143_ReorderList {
    public void reorderList(ListNode head) {
        int n =0;
        ListNode cur = head;
        while (cur != null){
            cur = cur.next;
            n++;
        }

        cur = head;
        for (int i = 0; i < Math.ceil(n/2.0);i++){
            cur = cur.next;
        }
    }
}