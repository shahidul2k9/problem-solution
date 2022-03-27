from random import randint
from typing import List


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.quickSort(nums, 0, len(nums) - 1)
        return nums

    def quickSort(self, nums, lo, hi):
        if lo < hi:
            r = randint(lo, hi)
            nums[hi], nums[r] = nums[r], nums[hi]
            left = lo - 1
            for i in range(lo, hi, 1):
                if nums[i] <= nums[hi]:
                    left = left + 1
                    nums[left], nums[i] = nums[i], nums[left]
            left = left + 1
            nums[left], nums[hi] = nums[hi], nums[left]
            self.quickSort(nums, lo, left - 1)
            self.quickSort(nums, left + 1, hi)


print(Solution().sortArray([4, 3, 1, 2, 7, 6, 5]))
