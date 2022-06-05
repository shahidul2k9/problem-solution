from typing import List


class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        min_num = nums[:]
        for i in range(n-2, -1, -1):
            min_num[i] = min(min_num[i+1], min_num[i])
        max_val = nums[0]
        for i in range(1, n):
            if max_val <= min_num[i]:
                return i
            else:
                max_val = max(max_val, nums[i])
        return -1