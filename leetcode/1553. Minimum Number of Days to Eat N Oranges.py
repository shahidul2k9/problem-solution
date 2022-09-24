class Solution:
    def minDays(self, n: int) -> int:
        dp = {0: 0, 1: 1}

        def find_min_days(r: int) -> int:
            if r not in dp:
                x = 1 + (r % 2) + find_min_days(r // 2)
                y = 1 + (r % 3) + find_min_days(r // 3)
                dp[r] = min(x, y)
            return dp[r]

        return find_min_days(n)