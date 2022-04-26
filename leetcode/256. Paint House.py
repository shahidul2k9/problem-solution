from typing import List


class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        m, n = len(costs), len(costs[0])
        dp = [[None] * n for _ in range(m)]

        def min_cost(r, c):
            if r < 0:
                return 0
            if dp[r][c] is not None:
                return dp[r][c]
            else:
                opt_cost = float('inf')
                for adj_color in range(n):
                    if adj_color != c:
                        opt_cost = min(opt_cost, costs[r][c] + min_cost(r - 1, adj_color))
                dp[r][c] = opt_cost
                return opt_cost

        opt_ans = float('inf')
        for color in range(n):
            opt_ans = min(opt_ans, min_cost(m - 1, color))
        return opt_ans

