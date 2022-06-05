from collections import Counter
from typing import List


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        frequency = list(Counter(nums).items())
        frequency.sort(key=lambda x: x[0])
        n = len(frequency)
        dp = [-1] * n

        def max_earn(pos) -> int:
            if pos < 0:
                return 0
            elif dp[pos] == -1:
                k, f = frequency[pos]
                local = 0
                if pos > 0 and frequency[pos - 1][0] + 1 == k:
                    local = max_earn(pos - 2)
                else:
                    local = max_earn(pos - 1)
                dp[pos] = max(k * f + local, max_earn(pos - 1))
            return dp[pos]

        return max_earn(n - 1)
