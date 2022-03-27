
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/24/2022
 **/
public class _199_BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> rightSideList = new ArrayList<>();
        collectClockwiseEdgeValues(root, 1, rightSideList);
        return rightSideList;
    }

    private void collectClockwiseEdgeValues(TreeNode root, int level, List<Integer> collector) {
        if (root != null) {
            if (level > collector.size()) {
                collector.add(root.val);
            }
            collectClockwiseEdgeValues(root.right, level + 1, collector);
            collectClockwiseEdgeValues(root.left, level + 1, collector);
        }
    }
}

