from typing import List


class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        m, n = len(grid), len(grid[0])
        remainder = grid[0][0] % x
        nums = []
        for r in range(m):
            for c in range(n):
                if grid[r][c] % x != remainder:
                    return -1
                nums.append(grid[r][c])
        nums.sort()
        target_average_int = nums[(m * n) // 2]
        operations = 0
        for row in grid:
            for val in row:
                operations += (abs(val - target_average_int) // x)
        return operations
