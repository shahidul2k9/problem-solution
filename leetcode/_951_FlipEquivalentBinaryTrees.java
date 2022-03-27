
/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _951_FlipEquivalentBinaryTrees {

    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        return fixTree(root1, root2);
    }

    private boolean fixTree(TreeNode sb1, TreeNode sb2) {
        if (sb1 == null && sb2 == null) {
            return true;
        } else if (sb1 == null || sb2 == null || sb1.val != sb2.val) {
            return false;
        } else {
            if (!isSameKey(sb1.left, sb2.left)) {
                TreeNode tempLeft = sb1.left;
                sb1.left = sb1.right;
                sb1.right = tempLeft;
            }
            if (isSameKey(sb1.left, sb2.left) && isSameKey(sb1.right, sb2.right)) {
                return fixTree(sb1.left, sb2.left) && fixTree(sb1.right, sb2.right);
            } else {
                return false;
            }
        }
    }

    private boolean isSameKey(TreeNode a, TreeNode b) {
        return a == null && b == null ||
                (a != null && b != null && a.val == b.val);
    }

}
