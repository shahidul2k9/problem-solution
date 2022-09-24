from typing import List


class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        left = right = 0
        window_sum = 0
        max_allowed_window = 1

        while right < n:
            window_sum += nums[right]
            while window_sum + k < nums[right] * (right - left + 1):
                window_sum -= nums[left]
                left += 1
            max_allowed_window = max(max_allowed_window, right - left + 1)
            right += 1
        return max_allowed_window

