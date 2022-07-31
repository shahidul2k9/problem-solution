from typing import List


class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        rank = [1] * (n * n)
        par = [p for p in range(n * n)]

        def find_parent(u) -> int:
            if par[u] == u:
                return u
            else:
                parent_of_u = find_parent(par[u])
                par[u] = parent_of_u
                return parent_of_u

        def union(u, v):
            pu = find_parent(u)
            pv = find_parent(v)
            if pu != pv:
                if rank[pu] < rank[pv]:
                    pu, pv = pv, pu
                rank[pu] += rank[pv]
                par[pv] = pu

        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    for dr, dc in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 1:
                            union(r * n + c, nr * n + nc)
        largest_island = 0
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 0:
                    this_island_size = 1
                    neighbours = set()
                    for dr, dc in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 1:
                            neighbours.add(find_parent(nr * n + nc))
                    for g in neighbours:
                        this_island_size += rank[g]
                    largest_island = max(largest_island, this_island_size)
        if largest_island == 0:
            largest_island = rank[find_parent(0)]
        return largest_island
