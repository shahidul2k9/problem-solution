
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _1305_AllElementsInTwoBinarySearchTrees {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {

        List<Integer> collector1 = new ArrayList<>();
        List<Integer> collector2 = new ArrayList<>();
        collectByInOrder(root1, collector1);
        collectByInOrder(root2, collector2);
        List<Integer> combiner = new ArrayList<>();
        int a, b;
        a = b = 0;
        while (a < collector1.size() && b < collector2.size()) {
            if (collector1.get(a) < collector2.get(b)) {
                combiner.add(collector1.get(a++));
            } else {
                combiner.add(collector2.get(b++));
            }
        }
        if (a < collector1.size())
            combiner.addAll(collector1.subList(a, collector1.size()));
        if (b < collector2.size())
            combiner.addAll(collector2.subList(b, collector2.size()));
        return combiner;

    }

    private void collectByInOrder(TreeNode sb, List<Integer> collector) {
        if (sb != null) {
            collectByInOrder(sb.left, collector);
            collector.add(sb.val);
            collectByInOrder(sb.right, collector);
        }
    }
}
