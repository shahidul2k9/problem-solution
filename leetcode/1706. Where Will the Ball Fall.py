from typing import List


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        bottom = [-1] * n

        def dfs(r, c, isUp):
            if r == m - 1 and not isUp:
                return [r, c, isUp]
            if isUp:
                if grid[r][c] == 1:
                    if c + 1 < n and grid[r][c + 1] == 1:
                        return dfs(r, c + 1, False)
                else:
                    if c - 1 >= 0 and grid[r][c - 1] == -1:
                        return dfs(r, c - 1, False)
            else:
                return dfs(r + 1, c, True)
            return [r, c, isUp]

        for c in range(n):
            br, bc, isUp = dfs(0, c, True)
            if br == m - 1 and not isUp:
                bottom[c] = bc
        return bottom