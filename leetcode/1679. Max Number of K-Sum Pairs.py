from collections import Counter
from typing import List


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        frequency = Counter(nums)
        max_ops = 0
        for x in nums:
            y = k - x
            fx = frequency[x]
            fy = frequency[y]
            if (x != y and (fx > 0 and fy > 0)) or (x == y and fx > 1):
                frequency[x] -= 1
                frequency[y] -= 1
                max_ops += 1
        return max_ops
