
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _95_UniqueBinarySearchTreesII {
    public List<TreeNode> generateTrees(int n) {
        TreeNode[][][] dp = new TreeNode[n + 1][n + 1][n + 1];
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                dp[r][c] = null;
            }
        }

        return Arrays.asList(constructBst(1, n, dp));
    }

    private TreeNode[] constructBst(int a, int b, TreeNode[][][] dp) {
        if (a > b) {
            return new TreeNode[]{null};
        } else if (dp[a][b] != null) {
            return dp[a][b];
        } else {
            if (a == b) {
                return dp[a][b] = new TreeNode[]{new TreeNode(a, null, null)};
            } else {
                //TreeNode[] rootList = new TreeNode[b - a + 1];
                List<TreeNode> rootList = new ArrayList<>();
                for (int i = a; i <= b; i++) {
                    TreeNode[] leftSubtreeList = constructBst(a, i - 1, dp);
                    TreeNode[] rightSubtreeList = constructBst(i + 1, b, dp);
                    for (TreeNode left : leftSubtreeList) {
                        for (TreeNode right : rightSubtreeList) {
                            rootList.add(new TreeNode(i, left, right));
                        }
                    }
                }
                return dp[a][b] = rootList.stream().toArray(TreeNode[]::new);
            }
        }
    }
}
