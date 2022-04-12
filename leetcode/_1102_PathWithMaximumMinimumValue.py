from heapq import heappop, heappush
from typing import List


class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])

        ans = grid[0][0]
        s = {0, 0}
        q = [[-grid[0][0], 0, 0]]

        while q:
            v, r, c = heappop(q)
            ans = min(-v, ans)
            for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < M and 0 <= nc < N and (nr, nc) not in s:
                    if nr == M - 1 and nc == N - 1:
                        return min(ans, grid[nr][nc])
                    s.add((nr, nc))
                    heappush(q, [-grid[nr][nc], nr, nc])
        return ans
