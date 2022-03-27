from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        def max_profit(s, dp):
            if s >= len(nums):
                return 0
            elif s in dp:
                return dp[s]
            else:
                dp[s] = max(nums[s] + max_profit(s + 2, dp), max_profit(s + 1, dp))
                return dp[s]

        if len(nums) == 1:
            return nums[0]
        else:
            last_val = nums.pop()
            ans = max_profit(0, dict())
            nums.append(last_val)
            nums.pop(0)
            return max(ans, max_profit(0, dict()))
