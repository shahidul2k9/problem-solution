from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        ps = 0
        remainders = {}
        for i, v in enumerate(nums):
            ps = (ps + v) % k
            if ps in remainders and i - remainders[ps] > 1 or (ps == 0 and i > 0):
                return True
            if ps not in remainders:
                remainders[ps] = i
        return False