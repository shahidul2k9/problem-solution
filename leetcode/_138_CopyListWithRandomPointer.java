
/**
 * @author Shahidul Islam
 * @date 2/26/2022
 **/
public class _138_CopyListWithRandomPointer {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        } else {
            Node cur = head;
            while (cur != null) {
                Node copiedNode = new Node(cur.val);
                copiedNode.next = cur.next;
                cur.next = copiedNode;
                cur = cur.next.next;
            }
            cur = head;
            while (cur != null) {
                cur.next.random = cur.random != null ? cur.random.next : null;
                cur = cur.next.next;
            }
            cur = head;
            head = head.next;
            Node newCur = head.next;
            while (cur != null) {
                cur.next = cur.next != null ? cur.next.next : null;
                newCur.next = newCur.next != null ? newCur.next.next : null;
                newCur = newCur.next;
                cur = cur.next;
            }
            return head;
        }


    }
}
