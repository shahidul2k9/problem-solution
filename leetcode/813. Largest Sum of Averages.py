from typing import List


class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        dp = [[None] * (k + 1) for _ in range(n)]
        pf = [0] * (n + 1)
        for i in range(n):
            pf[i + 1] = pf[i] + nums[i]

        def partition(pos, k):
            print(pos, k)
            if pos == n and k == 0:
                return 0
            elif k > (n - pos) or k <= 0:
                return float('-inf')
            elif dp[pos][k] is not None:
                return dp[pos][k]
            else:
                opt_val = 0
                for d in range(1, (n - pos) - k + 2, 1):
                    opt_val = max(opt_val, (pf[pos + d] - pf[pos]) / d + partition(pos + d, k - 1))
                dp[pos][k] = opt_val

                return opt_val

        return partition(0, k)
