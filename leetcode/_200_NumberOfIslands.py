from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        def dfs(r, c):
            grid[r][c] = '0'
            for dr, dc in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == '1':
                    dfs(nr, nc)

        R, C = len(grid), len(grid[0])
        island_count = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == '1':
                    dfs(r, c)
                    island_count += 1
        return island_count
