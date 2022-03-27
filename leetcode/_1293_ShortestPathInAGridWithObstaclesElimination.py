from typing import List
from collections import deque


class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        R, C = len(grid), len(grid[0])
        mh = R - 1 + C - 1
        if mh <= k:
            return mh
        s = (0, 0, k)
        q = deque([(0, s)])
        seen = {s}
        while q:
            d, (r, c, rk) = q.popleft()
            if r == R - 1 and c == C - 1:
                return d
            for nr, nc in [(r, c + 1), (r - 1, c), (r, c - 1), (r + 1, c)]:
                if 0 <= nr < R and 0 <= nc < C:
                    nrk = rk - grid[nr][nc]
                    ns = (nr, nc, nrk)
                    if nrk >= 0 and ns not in seen:
                        q.append((d + 1, ns))
                        seen.add(ns)
        return -1
