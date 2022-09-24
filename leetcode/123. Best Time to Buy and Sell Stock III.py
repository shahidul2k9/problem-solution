from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        profit_starting_at = [0] * (n + 1)
        max_val = prices[n - 1]
        for i in range(n - 1, -1, -1):
            profit_starting_at[i] = max(max_val - prices[i], profit_starting_at[i + 1])
            max_val = max(max_val, prices[i])
        min_val = prices[0]
        left_max_profit = 0
        total_profit = 0
        for i in range(n):
            left_max_profit = max(left_max_profit, prices[i] - min_val)
            min_val = min(min_val, prices[i])
            total_profit = max(total_profit, left_max_profit + profit_starting_at[i + 1])
        return total_profit
