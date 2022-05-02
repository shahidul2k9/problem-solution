from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [0] * n
        for r in range(m):
            for c in range(n):
                val = grid[r][c]
                if r == 0 and c == 0:
                    dp[c] = val
                elif r == 0:
                    dp[c] = dp[c-1] + val
                elif c == 0:
                    dp[c] = dp[c] + val
                else:
                    dp[c] = min(dp[c-1], dp[c]) + val
        return dp[n-1]