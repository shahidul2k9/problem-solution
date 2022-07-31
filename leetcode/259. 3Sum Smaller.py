from typing import List


class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        triplets = 0
        for i in range(n - 2):
            left = i + 1
            right = n - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] < target:
                    triplets += right - left
                    left += 1
                else:
                    right -= 1
        return triplets

