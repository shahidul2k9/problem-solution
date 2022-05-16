from typing import List


class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        dp = nums[:]
        for it in range(len(nums) - 1):
            for i in range(len(dp) - 1):
                dp[i] = (dp[i] + dp[i + 1]) % 10
            dp.pop()
        return dp[0]

