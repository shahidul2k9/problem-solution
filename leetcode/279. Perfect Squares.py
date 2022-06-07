from functools import lru_cache


class Solution:
    def numSquares(self, n: int) -> int:
        squared = []
        i = 1
        while i * i <= n:
            squared.append(i * i)
            i += 1

        dp = [n] * (n + 1)
        dp[0] = 0
        for val in range(1, n + 1):
            for x in squared:
                if x > val:
                    break
                else:
                    dp[val] = min(dp[val], dp[val - x] + 1)
        return dp[n]