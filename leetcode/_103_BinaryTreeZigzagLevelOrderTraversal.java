
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/25/2022
 **/
public class _103_BinaryTreeZigzagLevelOrderTraversal {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> zzLevel = new ArrayList<>();
        dfs(root, 0, zzLevel);
        return zzLevel;
    }

    private void dfs(TreeNode r, int l, List<List<Integer>> zzLevel) {
        if (r != null) {
            if (zzLevel.size() <= l) {
                zzLevel.add(new LinkedList<>());
            }
            if (l % 2 == 0) {
                zzLevel.get(l).add(r.val);
            } else {
                zzLevel.get(l).add(0, r.val);
            }
            dfs(r.left, l + 1, zzLevel);
            dfs(r.right, l + 1, zzLevel);
        }
    }
}
