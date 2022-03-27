
import java.util.ArrayList;
import java.util.List;

public class ListNode {
    public int val;
    public ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    public ListNode(int val, ListNode next) { this.val = val; this.next = next; }

    public static ListNode build(int[] valueList){
        if (valueList == null || valueList.length == 0){
            return null;
        }else {
            ListNode head = new ListNode(valueList[0]);
            ListNode tail = head;
            for (int i = 1; i < valueList.length;i++){
                tail.next = new ListNode(valueList[i], null);
                tail = tail.next;
            }
            return head;
        }
    }

    @Override
    public String toString() {
        List<Integer> valueCollector = new ArrayList<>();
        ListNode cur = this;
        while (cur != null){
            valueCollector.add(cur.val);
            cur = cur.next;
        }
        return valueCollector.toString();
    }
}