from typing import List


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sorted_nums = nums[:]
        sorted_nums.sort()
        i = 0
        j = len(nums) - 1
        while i <= j:
            if nums[i] == sorted_nums[i]:
                i += 1
            elif nums[j] == sorted_nums[j]:
                j -= 1
            else:
                break
        else:
            return 0
        return j - i + 1
