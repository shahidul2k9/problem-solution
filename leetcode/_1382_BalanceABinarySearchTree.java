
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _1382_BalanceABinarySearchTree {
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<TreeNode> nodeCollector = new ArrayList<>();
        collectNode(root, nodeCollector);
        return constructBst(0, nodeCollector.size() - 1, nodeCollector);
    }

    private TreeNode constructBst(int a, int b, List<TreeNode> nodeList) {
        if (a > b) {
            return null;
        } else {
            int mid = (a + b) / 2;
            TreeNode sr = nodeList.get(mid);
            sr.left = constructBst(a, mid - 1, nodeList);
            sr.right = constructBst(mid + 1, b, nodeList);
            return sr;
        }
    }

    private void collectNode(TreeNode sr, List<TreeNode> collector) {
        if (sr != null) {
            collectNode(sr.left, collector);
            collector.add(sr);
            collectNode(sr.right, collector);
        }
    }
}
