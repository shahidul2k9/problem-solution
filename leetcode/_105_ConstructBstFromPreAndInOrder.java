
import java.util.Arrays;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * @author Shahidul Islam
 * @date 2/22/2022
 **/
public class _105_ConstructBstFromPreAndInOrder {
    private int potId = 0;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        AtomicInteger indexCounter = new AtomicInteger(0);
        Map<Integer, Integer> rootMap = Arrays.stream(inorder)
                .boxed()
                .collect(Collectors.toMap(Function.identity(), vx -> indexCounter.getAndIncrement()));

        return constructBinaryTree(preorder, 0, inorder.length - 1, rootMap);
    }

    private TreeNode constructBinaryTree(int[] preorder, int a, int b, Map<Integer, Integer> rootMap) {
        if (a > b) {
            return null;
        } else {
            int rootVal = preorder[potId++];
            Integer rootPos = rootMap.get(rootVal);
            TreeNode left = constructBinaryTree(preorder, a, rootPos - 1, rootMap);
            TreeNode right = constructBinaryTree(preorder, rootPos + 1, b, rootMap);
            return new TreeNode(rootVal, left, right);
        }
    }

}
