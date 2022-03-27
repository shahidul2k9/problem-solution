
/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _129_SumRootToLeafNumbers {
    public int sumNumbers(TreeNode root) {
        return sumRooToLeaf(root, 0);
    }

    private int sumRooToLeaf(TreeNode sr, int x) {
        if (sr == null) {
            return x;
        } else {
            int nx = x * 10 + sr.val;
            if (sr.left == null && sr.right == null) {
                return nx;
            } else {
                int total = 0;
                if (sr.left != null) {
                    total += sumRooToLeaf(sr.left, nx);
                }
                if (sr.right != null) {
                    total += sumRooToLeaf(sr.right, nx);
                }
                return total;
            }

        }
    }
}
