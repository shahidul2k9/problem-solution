from functools import lru_cache
from typing import List


class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        # @lru_cache
        def minimize_max_sum(n, rm):
            if (rm > 0 and n <= 0) or (rm <= 0 and n > 0):
                return float('inf')
            elif dp[n][rm] != None:
                return dp[n][rm]
            else:
                min_val = float('inf')
                for i in range(n, 0, -1):
                    if ps[n] - ps[i - 1] >= min_val:
                        break
                    min_val = min(max(ps[n] - ps[i - 1], minimize_max_sum(i - 1, rm - 1)), min_val)
                dp[n][rm] = min_val
                return min_val

        N = len(nums)
        ps = [0] * (N + 1)
        for i in range(1, N + 1):
            ps[i] = nums[i - 1] + ps[i - 1]
        dp = [[None] * (m + 1) for _ in range(N + 1)]
        dp[0][0] = 0
        return minimize_max_sum(N, m)