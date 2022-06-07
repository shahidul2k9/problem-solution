from typing import List


class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        color = [row[:] for row in grid]

        def is_closed(r, c) -> bool:
            closed = True
            color[r][c] = 2

            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nx, ny = r + dx, c + dy

                if not (0 <= nx < m and 0 <= ny < n):
                    closed = False
                elif color[nx][ny] == 0:
                    next_closed = is_closed(nx, ny)
                    closed = closed and next_closed
            return closed

        closed_islands = 0
        for r in range(m):
            for c in range(n):
                if color[r][c] == 0:
                    closed_islands += (1 if is_closed(r, c) else 0)
                    # for row in color:
                    #     print(''.join(map(str, row)))
        return closed_islands