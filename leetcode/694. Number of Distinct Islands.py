from typing import List


class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(r, c, seq):
            seq.append([r, c])
            grid[r][c] = 0
            for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                    dfs(nr, nc, seq)

        island_set = set()
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    seq = []
                    dfs(r, c, seq)
                    rm = cm = float('inf')
                    for a, b in seq:
                        rm = min(rm, a)
                        cm = min(cm, b)
                    island = []
                    for rnc in seq:
                        island.append((rnc[0] - rm, rnc[1] - cm))
                    island.sort()
                    island_set.add(tuple(island))
        return len(island_set)


