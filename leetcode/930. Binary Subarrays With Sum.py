import collections
from typing import List


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        psf = collections.defaultdict(int)
        psf[0] = 1
        subarrays = 0
        s = 0
        for v in nums:
            s += v
            subarrays += psf[s-goal]
            psf[s] += 1
        return subarrays