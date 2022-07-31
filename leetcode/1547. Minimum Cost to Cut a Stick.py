from typing import List


class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        pn = len(cuts)
        dp = [[-1] * pn for _ in range(pn)]
        cuts.sort()

        def find_min_cost(i, k, a, b) -> int:
            if i > k:
                return 0
            if dp[i][k] == -1:
                min_cost = float('inf')
                for mid in range(i, k + 1):
                    min_cost = min(min_cost,
                                   find_min_cost(i, mid - 1, a, cuts[mid]) + find_min_cost(mid + 1, k, cuts[mid], b) + (
                                               b - a))
                dp[i][k] = min_cost
            return dp[i][k]

        return find_min_cost(0, pn - 1, 0, n)

