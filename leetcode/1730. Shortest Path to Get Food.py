import collections
from typing import List


class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        q = collections.deque()
        visited = set()
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '*':
                    q.append([r, c])
                    visited.add((r, c))

        level = 0
        while q:
            ln = len(q)
            while ln > 0:
                r, c = q.popleft()
                if grid[r][c] == '#':
                    return level
                for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                    nr, nc = r + dx, c + dy
                    if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited and grid[nr][nc] != 'X':
                        q.append([nr, nc])
                        visited.add((nr, nc))
                ln -= 1
            level += 1
        return -1
