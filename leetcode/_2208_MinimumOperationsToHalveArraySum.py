from heapq import heappush, heappop
from typing import List


class Solution:
    def halveArray(self, nums: List[int]) -> int:
        pq = []
        for v in nums:
            heappush(pq, -v)
        half = sum(nums) / 2
        removed = 0
        min_operation = 0
        while removed < half:
            h = heappop(pq) / 2
            removed = removed - h
            heappush(pq, h)
            min_operation += 1
        return min_operation
