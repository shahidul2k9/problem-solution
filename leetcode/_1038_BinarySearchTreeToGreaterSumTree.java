
/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _1038_BinarySearchTreeToGreaterSumTree {
    public TreeNode bstToGst(TreeNode root) {
        constructGst(root, 0);
        return root;
    }

    private int constructGst(TreeNode n, int pc) {
        if (n == null) {
            return 0;
        }
        int originalVal = n.val;
        int rightTotal = constructGst(n.right, pc);
        n.val = pc + originalVal + rightTotal;
        int leftTotal = constructGst(n.left, n.val);
        return leftTotal + originalVal + rightTotal;
    }
}
