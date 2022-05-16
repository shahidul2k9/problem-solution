class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [[None] * (target + 1) for _ in range(n + 1)]

        def ways(rem_n, rem_target):
            if rem_n == 0 and rem_target == 0:
                return 1
            elif rem_n <= 0 or rem_target <= 0:
                return 0
            if dp[rem_n][rem_target] != None:
                return dp[rem_n][rem_target]
            total_ways = 0
            for f in range(1, min(rem_target, k) + 1):
                total_ways = (total_ways + ways(rem_n - 1, rem_target - f)) % (10 ** 9 + 7)
            dp[rem_n][rem_target] = total_ways
            return total_ways

        return ways(n, target)

