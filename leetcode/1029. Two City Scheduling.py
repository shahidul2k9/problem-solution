from typing import List


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs) // 2
        dp = [[-1] * (n + 1) for _ in range(2 * n + 1)]

        def find_cost(index: int, an: int) -> int:
            if index == 0:
                if an == 0:
                    return 0
                else:
                    return float('inf')
            elif dp[index][an] == -1:
                ans = find_cost(index - 1, an) + costs[index - 1][1]
                if an > 0:
                    ans = min(ans, find_cost(index - 1, an - 1) + costs[index - 1][0])
                dp[index][an] = ans
            return dp[index][an]

        return find_cost(2 * n, n)
