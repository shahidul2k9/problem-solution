from heapq import heappop, heappush
from typing import List


class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        hq = []
        for sl in sticks:
            heappush(hq, sl)
        cost = 0
        while len(hq) >= 2:
            sl = heappop(hq) + heappop(hq)
            heappush(hq, sl)
            cost += sl
        return cost
