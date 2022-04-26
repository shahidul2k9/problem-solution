from typing import List


class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        start = 0
        sub_arrays = 0
        group = 0
        for i, v in enumerate(nums):
            sub_arrays += group
            if left <= v <= right:
                group = (i - start + 1)
            else:
                if v > right:
                    start = i + 1
                    group = 0
        sub_arrays += group
        return sub_arrays

