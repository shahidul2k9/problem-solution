
/**
 * @author Shahidul Islam
 * @date 2/23/2022
 **/
public class _222_CountCompleteTreeNodes {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        } else return 1 + countNodes(root.left) + countNodes(root.right);

    }
}
