from typing import List


class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        for c in range(n):
            if grid[0][c] == 1:
                for r in range(m):
                    grid[r][c] = 1 - grid[r][c]
        for r in range(1, m):
            row_sum = sum(grid[r])
            if row_sum != 0 and row_sum != n:
                return False
        return True