from functools import lru_cache
from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache
        def fin_max(s, including):
            if s >= len(nums):
                return 0
            else:
                if including:
                    return nums[s] + fin_max(s + 1, False)
                else:
                    return max(fin_max(s + 1, True), fin_max(s + 1, False))

        return max(fin_max(0, True), fin_max(0, False))
