import collections
from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        n = len(nums)
        max_consecutive_ones = 0

        zq = collections.deque()
        left = right = 0
        while right < n:
            if nums[right] == 0:
                zq.append(right)
            if len(zq) >= 2:
                left = zq.popleft() + 1
            max_consecutive_ones = max(max_consecutive_ones, right - left + 1)
            right += 1
        return max_consecutive_ones




