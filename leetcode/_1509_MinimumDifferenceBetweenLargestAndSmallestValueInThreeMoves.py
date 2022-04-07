from typing import List


class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4:
            return 0
        else:
            nums.sort()
            minimum_diff = float('inf')
            for remove_at_beginning in range(4):
                minimum_diff = min(minimum_diff, nums[n - 4 + remove_at_beginning] - nums[remove_at_beginning])
            return minimum_diff
