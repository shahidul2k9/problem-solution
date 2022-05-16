from typing import List


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        optional_suffix = [0] * (n + 1)
        suffix_sum = 0
        for j in range(n - 1, -1, -1):
            suffix_sum += nums[j]
            optional_suffix[j] = max(optional_suffix[j + 1], suffix_sum)

        dp_ending_i = 0
        prefix_sum = 0

        opt_max = float('-inf')
        for i in range(n):
            prefix_sum += nums[i]
            dp_ending_i = nums[i] + max(0, dp_ending_i)
            opt_max = max(opt_max, dp_ending_i, prefix_sum + optional_suffix[i + 1])
        return opt_max

