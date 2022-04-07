from typing import List


class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        max_pair_sum = 0
        for i in range(len(nums) // 2):
            max_pair_sum = max(max_pair_sum, nums[i] + nums[len(nums) - 1 - i])
        return max_pair_sum
