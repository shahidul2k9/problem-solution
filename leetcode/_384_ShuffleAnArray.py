import random
from typing import List


class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.originalCopy = nums.copy()

    def reset(self) -> List[int]:
        for i in range(len(self.nums)):
            self.nums[i] = self.originalCopy[i]
        return self.nums

    def shuffle(self) -> List[int]:
        n = len(self.nums)
        for i in range(n - 1, -1, -1):
            r = random.randint(0, i)
            self.nums[r], self.nums[i] = self.nums[i], self.nums[r]
        return self.nums
