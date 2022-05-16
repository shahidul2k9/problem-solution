from heapq import heappush, heappop
from typing import List


class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])
        efforts = [[-1] * n for _ in range(m)]
        hq = [[0, 0, 0]]
        while hq:
            ef, r, c = heappop(hq)
            if r == m - 1 and c == n - 1:
                return ef
            if efforts[r][c] == -1:
                efforts[r][c] = ef
                for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                    ajr, ajc = r + dr, c + dc
                    if 0 <= ajr < m and 0 <= ajc < n and efforts[ajr][ajc] == -1:
                        heappush(hq, [max(abs(heights[r][c] - heights[ajr][ajc]), ef), ajr, ajc])


