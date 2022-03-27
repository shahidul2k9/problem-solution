
import java.util.HashMap;
import java.util.Map;

class _235_LcaOfBst {
    private static class Pair{
        public TreeNode node;
        public Integer depth;

        Pair(TreeNode node, Integer depth){
            this.node = node;
            this.depth = depth;
        }
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Map<TreeNode, Pair> depthMap = new HashMap<>();
        buildDepth(root, depthMap, 0, null);
        while ( p != q){
            Pair nodeP = depthMap.get(p);
            Pair nodeQ = depthMap.get(q);
            if (nodeP.depth > nodeQ.depth){
                p = nodeP.node;
            }else {
                q = nodeQ.node;
            }
        }
        return p;
    }
    private void buildDepth(TreeNode node, Map<TreeNode, Pair> depthMap, int depth, TreeNode parent){
        if (node != null){
            depthMap.put(node, new Pair(parent, depth) );
            buildDepth(node.left, depthMap, depth + 1, node);
            buildDepth(node.right, depthMap, depth + 1, node);
        }
    }
}