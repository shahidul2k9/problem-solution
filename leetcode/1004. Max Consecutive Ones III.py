from typing import List
import collections


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        right = 0
        ans = 0
        zq = collections.deque()
        while right < len(nums):
            if nums[right] == 0:
                zq.append(right)
                if len(zq) > k:
                    left = zq.popleft() + 1
            right += 1
            ans = max(ans, right - left)
        return ans
