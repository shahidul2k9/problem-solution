
/**
 * @author Shahidul Islam
 * @date 2/23/2022
 **/
public class _114_FlattenBinaryTreeToLinkedList {
    public void flatten(TreeNode root) {
        if (root != null) {
            TreeNode left = root.left;
            flatten(left);
            TreeNode right = root.right;
            flatten(right);
            root.left = null;
            root.right = mergeNode(left, right);
        }


    }

    private TreeNode mergeNode(TreeNode left, TreeNode right) {
        TreeNode sentinelHead = new TreeNode(0, null, null);
        TreeNode cur = sentinelHead;
        while (left != null) {
            cur.right = left;
            cur = cur.right;
            left = left.right;
        }
        while (right != null) {
            cur.right = right;
            cur = cur.right;
            right = right.right;
        }
        return sentinelHead.right;
    }
}
