from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        s = 1
        k = 0
        for i in range(1, len(nums)):
            if nums[k] == nums[i]:
                s += 1
            else:
                s = 1
            if s <= 2:
                k += 1
                nums[k] = nums[i]
        return k + 1
