
class _226_InvertBinaryTree {
    public TreeNode invertTree(TreeNode root) {
        if (root == null){
            return root;
        }else {
            invertTree(root.left);
            invertTree(root.right);
            TreeNode left = root.left;
            root.left = root.right;
            root.right = left;
            return root;
        }
    }
}