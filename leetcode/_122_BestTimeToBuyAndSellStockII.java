
import java.util.Stack;

/**
 * @author Shahidul Islam
 * @date 1/30/2022
 **/
public class _122_BestTimeToBuyAndSellStockII {
    public int maxProfit(int[] prices) {
        Stack<Integer> stack = new Stack<>();
        int totalProfit = 0;
        for (int price : prices) {
            if (!stack.isEmpty() && price < stack.peek()) {
                totalProfit += sellStock(stack);
            }
            stack.push(price);

        }
        totalProfit += sellStock(stack);
        return totalProfit;

    }

    private int sellStock(Stack<Integer> stack) {

        int profit;
        if (stack.size() >= 2) {
            profit = stack.pop() - stack.get(0);
        } else {
            profit = 0;
        }
        stack.clear();
        return profit;
    }
}
