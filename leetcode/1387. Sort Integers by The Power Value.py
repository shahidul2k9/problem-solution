class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        dp = {1: 0}

        def find_power(x) -> int:
            if x not in dp:
                if x & 1:
                    dp[x] = 1 + find_power(3 * x + 1)
                else:
                    dp[x] = 1 + find_power(x // 2)
            return dp[x]

        powers = []
        for x in range(lo, hi + 1):
            powers.append([find_power(x), x])
        powers.sort()
        return powers[k - 1][1]

