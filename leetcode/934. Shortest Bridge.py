import collections
from typing import List


class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        color = [[-1] * n for _ in range(m)]
        q = collections.deque()

        def collect_source(r, c):
            q.append([r, c, 0])
            color[r][c] = 0
            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nr, nc = r + dx, c + dy
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1 and color[nr][nc] == -1:
                    collect_source(nr, nc)

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    collect_source(r, c)
                    break
            if len(q) > 0:
                break
        while q:
            r, c, d = q.popleft()
            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nr, nc = r + dx, c + dy
                if 0 <= nr < m and 0 <= nc < n and color[nr][nc] == -1:
                    if grid[nr][nc] == 1:
                        return d
                    else:
                        q.append([nr, nc, d + 1])
                        color[nr][nc] = 0


