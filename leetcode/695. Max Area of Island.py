from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        color = [row[:] for row in grid]

        def visit_island(r, c) -> int:
            sz = 1
            for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                ajr, ajc = r + dr, c + dc
                if 0 <= ajr < m and 0 <= ajc < n and color[ajr][ajc] == 1:
                    color[ajr][ajc] = 0
                    sz += visit_island(ajr, ajc)
            return sz

        max_island_sz = 0
        for r in range(m):
            for c in range(n):
                if color[r][c] == 1:
                    color[r][c] = 0
                    max_island_sz = max(max_island_sz, visit_island(r, c))
        return max_island_sz


