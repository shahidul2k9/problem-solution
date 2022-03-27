from typing import List
from collections import defaultdict


class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        fc = defaultdict(int)
        fc[0] += 1
        ps = 0
        sc = 0
        for v in nums:
            ps += v % 2
            sc += fc[ps - k]
            fc[ps] += 1
        return sc
