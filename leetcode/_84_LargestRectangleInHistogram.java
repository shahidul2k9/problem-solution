
import java.util.Stack;

/**
 * @author Shahidul Islam
 * @date 2/6/2022
 **/
public class _84_LargestRectangleInHistogram {
    private static class ExtendedBar {
        public ExtendedBar(int s, int h) {
            this.s = s;
            this.h = h;
        }
        public int s;
        public int h;
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<ExtendedBar> stack = new Stack<>();
        int maxArea = Integer.MIN_VALUE;
        stack.push(new ExtendedBar(-1, 0));
        for (int i = 0; i < n; i++) {
            ExtendedBar newBar = new ExtendedBar(i, heights[i]);
            while (stack.peek().h > newBar.h) {
                ExtendedBar top = stack.pop();
                maxArea = Math.max(maxArea, (i - top.s)*top.h);
                newBar.s = top.s;
            }
            stack.add(newBar);
        }
        while (!stack.isEmpty()) {
            ExtendedBar top = stack.pop();
            maxArea = Math.max(maxArea, (n - top.s)*top.h);
        }
        return maxArea;

    }
}
