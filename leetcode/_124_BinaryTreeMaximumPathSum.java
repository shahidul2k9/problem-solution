
/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _124_BinaryTreeMaximumPathSum {
    private int mps = Integer.MIN_VALUE;
    private int inf = 100000;

    public int maxPathSum(TreeNode root) {
        computeMaxStrand(root);
        return mps;
    }

    private int computeMaxStrand(TreeNode st) {
        if (st == null) {
            return -inf;
        } else {
            int leftStrand = computeMaxStrand(st.left);
            int rightStrand = computeMaxStrand(st.right);
            int sbStrand = Math.max(Math.max(leftStrand, rightStrand) + st.val, st.val);
            mps = Math.max(Math.max(sbStrand, leftStrand + rightStrand + st.val), mps);
            return sbStrand;
        }
    }
}
