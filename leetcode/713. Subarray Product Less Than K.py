from typing import List


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        pd = 1
        left = right = ans = 0
        while right < len(nums):
            v = nums[right]
            while left < right and pd * v >= k:
                ans += right - left
                pd /= nums[left]
                left += 1

            if pd * v < k:
                pd *= v
            else:
                pd = 1
                left = right + 1
            right += 1
        n = right - left
        return ans + (n * (n + 1)) // 2

