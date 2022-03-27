
class _572_SubTreeOfAnotherTree {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (isSameTree(root, subRoot)) {
            return true;
        } else if (root == null && subRoot != null){
            return false;
        }else return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);


    }

    private boolean isSameTree(TreeNode root, TreeNode subRoot) {
        if (root == subRoot) return true;
        else if (root != null && subRoot != null) {
            return root.val == subRoot.val && isSameTree(root.left, subRoot.left) && isSameTree(root.right, subRoot.right);
        }
        return false;
    }
}