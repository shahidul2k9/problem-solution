from heapq import heappop, heappush
from typing import List


class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        pq = []
        for i in range(1, len(heights)):
            h1 = heights[i - 1]
            h2 = heights[i]
            if h1 < h2:
                heappush(pq, h2 - h1)
                if ladders > 0:
                    ladders -= 1
                elif bricks >= pq[0]:
                    bricks -= heappop(pq)
                else:
                    return i - 1
        return len(heights) - 1
