
import java.util.Arrays;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * @author Shahidul Islam
 * @date 2/22/2022
 **/
public class _106_ConstructBstFromInAndPostOderTraversal {
    private int postOrderRootIndex;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        AtomicInteger indexCounter = new AtomicInteger(0);

        Map<Integer, Integer> inorderIndexMap = Arrays.stream(inorder)
                .boxed()
                .collect(Collectors.toMap(Function.identity(), val -> indexCounter.getAndIncrement()));
        postOrderRootIndex = postorder.length - 1;
        return deserializeBinaryTree(postorder, 0, postorder.length - 1, inorderIndexMap);

    }

    private TreeNode deserializeBinaryTree(int[] postOrder, int a, int b, Map<Integer, Integer> integerIntegerMap) {
        if (a > b)
            return null;
        else {
            int rootKey = postOrder[postOrderRootIndex--];
            Integer rootIndexInOrder = integerIntegerMap.get(rootKey);
            TreeNode right = deserializeBinaryTree(postOrder, rootIndexInOrder + 1, b, integerIntegerMap);
            TreeNode left = deserializeBinaryTree(postOrder, a, rootIndexInOrder - 1, integerIntegerMap);
            return new TreeNode(rootKey, left, right);
        }
    }
}
