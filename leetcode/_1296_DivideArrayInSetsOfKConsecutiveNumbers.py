from typing import List
from collections import Counter


class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        s = Counter(nums)
        nums.sort()
        for v in nums:
            if s[v] > 0:
                ck = 0
                while ck < k and s[v + ck] > 0:
                    s[v + ck] -= 1
                    ck += 1
                if ck < k:
                    return False
        return True
