from functools import lru_cache
from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)
        if total_sum & 1:
            return False

        half = total_sum / 2

        @lru_cache(maxsize=None)
        def dfs(pos, target):
            if target == 0:
                return True
            elif pos < 0:
                return False
            return dfs(pos - 1, target) or (nums[pos] <= target and dfs(pos - 1, target - nums[pos]))

        return dfs(len(nums) - 1, half)
