import collections
from typing import List


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        if grid[0][0] == 1 or grid[R - 1][C - 1] == 1:
            return -1
        q = collections.deque()
        q.append((0, 0, 1))
        grid[0][0] = 1
        while q:
            r, c, d = q.popleft()
            if r == R - 1 and c == C - 1:
                return d
            for dr, dc in [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 0:
                    q.append((nr, nc, d + 1))
                    grid[nr][nc] = 1
        print(grid)
        return -1

