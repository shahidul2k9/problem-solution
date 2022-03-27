
/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _98_ValidateBinarySearchTree {
    private static class Vr {
        public Vr(int min, int max, boolean isValid) {
            this.min = min;
            this.max = max;
            this.isValid = isValid;
        }

        public int min;
        public int max;
        public boolean isValid;

    }

    public boolean isValidBST(TreeNode root) {
        return validate(root).isValid;
    }

    private Vr validate(TreeNode node) {
        if (node == null) {
            return new Vr(0, 0, true);
        } else {
            Vr validT = new Vr(node.val, node.val, true);
            Vr left = node.left == null ? validT : validate(node.left);
            Vr right = node.right == null ? validT : validate(node.right);
            Vr inValidT = new Vr(node.val, node.val, false);
            if (left.isValid && right.isValid && (node.left == null || node.val > left.max)
                    && (node.right == null || node.val < right.min)) {
                return new Vr(Math.min(left.min, right.min), Math.max(left.max, right.max), true);
            } else {
                return inValidT;
            }
        }
    }
}
