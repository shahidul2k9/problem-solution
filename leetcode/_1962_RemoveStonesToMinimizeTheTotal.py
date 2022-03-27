from heapq import heappush, heappop
from math import floor
from typing import List


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        pq = []
        for s in piles:
            heappush(pq, -s)
        removed_piles = 0
        while pq[-1] < -1 and k > 0:
            s = -1 * heappop(pq)
            removed = floor(s / 2)
            removed_piles += removed
            heappush(pq, -(s - removed))
            k -= 1
        return sum(piles) - removed_piles
