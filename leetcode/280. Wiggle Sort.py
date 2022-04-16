from typing import List


class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(1, len(nums)):
            if i & 1:
                if nums[i - 1] > nums[i]:
                    nums[i - 1], nums[i] = nums[i], nums[i - 1]
            else:
                if nums[i - 1] < nums[i]:
                    nums[i - 1], nums[i] = nums[i], nums[i - 1]

