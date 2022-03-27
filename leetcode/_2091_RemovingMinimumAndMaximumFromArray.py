from typing import List


class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        x, y = 0, 0
        n = len(nums)
        for i, v in enumerate(nums):
            if v < nums[x]:
                x = i
            if v > nums[y]:
                y = i
        if x > y:
            x, y = y, x

        return min(x + 1 + n - y, y + 1, n - x)
