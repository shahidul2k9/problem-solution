import collections
from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        fc = collections.defaultdict(int)
        fc[0] = 1
        cs = 0
        ans = 0
        for v in nums:
            cs += v
            fc[cs] += 1
            if k == 0:
                ans -= 1
            ans += fc[cs - k]
        return ans
