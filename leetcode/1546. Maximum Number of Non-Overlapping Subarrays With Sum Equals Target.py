from typing import List


class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        prefix_map = {0: -1}
        prefix = 0
        last_index = -1
        arrays = 0
        for i, v in enumerate(nums):
            prefix += v
            left_val = prefix - target
            if left_val in prefix_map and prefix_map[left_val] >= last_index:
                arrays += 1
                last_index = i
            prefix_map[prefix] = i
        return arrays
