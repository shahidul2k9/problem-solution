from heapq import heappop, heappush
from typing import List


class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        # yi + yj + |xi - xj| => (yi - xi) + (yj + xj) if xi < xj
        pq = []  # max priority queue of yi - xi
        opt_max_val = float('-inf')
        for index, (xj, yj) in enumerate(points):
            while pq:
                i = pq[0][1]
                if xj - points[i][0] <= k:
                    break
                heappop(pq)
            if pq:
                neg_yj_minus_xj, i = pq[0]
                opt_max_val = max(opt_max_val, -neg_yj_minus_xj + yj + xj)
            heappush(pq, [-(yj - xj), index])
        return opt_max_val
