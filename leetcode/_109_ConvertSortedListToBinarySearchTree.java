
/**
 * @author Shahidul Islam
 * @date 2/22/2022
 **/
public class _109_ConvertSortedListToBinarySearchTree {
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null)
            return null;
        else {
            ListNode rootPrev = findMiddlePreviousNode(head);
            if (rootPrev.next == null) {
                return new TreeNode(rootPrev.val, null, null);
            } else {
                ListNode rootNode = rootPrev.next;
                rootPrev.next = null;
                TreeNode left = sortedListToBST(head);
                TreeNode right = sortedListToBST(rootNode.next);
                return new TreeNode(rootNode.val, left, right);
            }
        }
    }

    private ListNode findMiddlePreviousNode(ListNode head) {
        ListNode prev, slow, fast;
        prev = slow = fast = head;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        return prev;
    }
}
