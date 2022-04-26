from typing import List


class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        window_sz = sum(nums)
        right = 0
        running_ones = 0
        ans = window_sz
        while right < n + window_sz - 1:
            running_ones += nums[right % n]
            right += 1

            if right >= window_sz:
                ans = min(ans, window_sz - running_ones)
                running_ones -= nums[right - window_sz]
        return ans



