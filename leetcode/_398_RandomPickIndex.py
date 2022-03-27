import random
from typing import List


class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        c = 0
        rIndex = -1
        for i in range(len(self.nums)):
            if self.nums[i] == target:
                c += 1
                if random.randint(1, c) == c:
                    rIndex = i
        return rIndex
