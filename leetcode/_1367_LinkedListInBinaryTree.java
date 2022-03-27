
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _1367_LinkedListInBinaryTree {
    public boolean isSubPath(ListNode head, TreeNode root) {
        return hasSubPathStartingAtAnyNode(head, root);
    }

    private boolean hasSubPathStartingAtAnyNode(ListNode head, TreeNode node) {

        if (node == null)
            return false;
        else if (hasPath(head, node)) {
            return true;
        } else {
            return hasSubPathStartingAtAnyNode(head, node.left)
                    || hasSubPathStartingAtAnyNode(head, node.right);
        }
    }

    private boolean hasPath(ListNode head, TreeNode node) {
        if (head == null)
            return true;
        else
            return node != null && head.val == node.val && (hasPath(head.next, node.left) || hasPath(head.next, node.right));
    }
}
