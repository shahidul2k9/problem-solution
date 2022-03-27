
import java.util.ArrayList;
import java.util.List;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode() {
    }

    public TreeNode(int val) {
        this.val = val;
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        ArrayList<Integer> collector = new ArrayList<>();
        inOrderCollector(this, collector);
        return collector.toString();
    }
    private void inOrderCollector(TreeNode root, List<Integer> collector){
        if (root == null){
            collector.add(null);
        }else {
            inOrderCollector(root.left, collector);
            collector.add(root.val);
            inOrderCollector(root.right, collector);
        }
    }
}