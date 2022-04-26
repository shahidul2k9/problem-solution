import math
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        s = sum(piles)

        def is_possible(k):
            th = 0
            for p in piles:
                th += math.ceil(p / k)
                if th > h:
                    return False
            return th <= h

        low = 1
        high = s
        ans = 0
        while low <= high:
            mid = (low + high) // 2
            if is_possible(mid):
                high = mid - 1
                ans = mid
            else:
                low = mid + 1
        return ans
