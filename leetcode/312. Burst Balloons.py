from functools import lru_cache
from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums.insert(0, 1)
        nums.append(1)
        n = len(nums)
        dp = [[-1] * n for _ in range(n)]

        @lru_cache(None)
        def brust_ballons(i, k) -> int:
            if i > k:
                return 0
            max_points = 0
            for p in range(i, k + 1):
                points = nums[p] * nums[i - 1] * nums[k + 1]
                points += brust_ballons(i, p - 1) + brust_ballons(p + 1, k)
                max_points = max(max_points, points)
            return max_points

        return brust_ballons(1, n - 2)