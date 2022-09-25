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
import java.util.Map;
import java.util.HashMap;
class _1836_RemoveDuplicatesFromAnUnsortedLinkedList {
    public ListNode deleteDuplicatesUnsorted(ListNode head) {

        Map<Integer, Integer> frequencyMap = new HashMap<>();
        ListNode cur = head;
        while (cur != null){
            frequencyMap.put(cur.val, frequencyMap.getOrDefault(cur.val, 0) + 1);
            cur = cur.next;
        }
        cur = head;
        ListNode sentinel = new ListNode(-1, head);
        ListNode copyHead = sentinel;
        while (cur != null){
            if (frequencyMap.get(cur.val) == 1){
                copyHead.next.val = cur.val;
                copyHead = copyHead.next;
            }
            cur = cur.next;
        }
        copyHead.next = null;
        return sentinel.next;

    }
}