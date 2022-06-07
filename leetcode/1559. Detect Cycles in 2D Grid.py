from typing import List


class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        visited = set()

        def dfs(x, y, par) -> bool:
            visited.add((x, y))
            for dx, dy in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    if grid[nx][ny] == grid[x][y]:
                        if (nx, ny) in visited:
                            if (nx, ny) != par:
                                print(x, y, nx, ny, par)
                                return True
                        else:
                            if dfs(nx, ny, (x, y)):
                                return True
            return False

        for r in range(m):
            for c in range(n):
                if (r, c) not in visited:
                    if dfs(r, c, (-1, -1)):
                        return True
        return False
