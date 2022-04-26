from typing import List


class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        next_val = 0
        for v in arr:
            next_val = min(v, next_val + 1)
        return next_val

