from typing import List


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        triplets = 0
        for i in range(n):
            k = i + 2
            for j in range(i + 1, n):
                while k < n and nums[i] + nums[j] > nums[k]:
                    k += 1
                k = max(k, j + 1)
                triplets += k - (j + 1)
        return triplets
