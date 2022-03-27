
import java.util.ArrayList;
import java.util.List;

class _21_MergeTwoSortedList {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        List<ListNode> nodeList = new ArrayList<>();
        while (list1 != null && list2 != null){
            if (list1.val < list2.val){
                nodeList.add(list1);
                list1 = list1.next;
            }else {
                nodeList.add(list2);
                list2 = list2.next;
            }
        }
        while (list1 != null){
            nodeList.add(list1);
            list1 = list1.next;
        }
        while (list2 != null){
            nodeList.add(list2);
            list2 = list2.next;
        }
        ListNode head = nodeList.size() > 0 ? nodeList.get(0) : null;
        ListNode currentNode = head;
        for (int i = 1; i < nodeList.size(); i++){
            currentNode.next = nodeList.get(i);
            currentNode = currentNode.next;
        }
        return head;
    }

}