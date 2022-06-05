from typing import List


class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        colored_grid = [row[:] for row in grid]
        m, n = len(grid), len(grid[0])
        visited = set()

        def dfs(r, c, search_color):
            visited.add((r, c))
            neighbours = []
            for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                next_r, next_c = r + dr, c + dc
                if 0 <= next_r < m and 0 <= next_c < n and grid[next_r][next_c] == search_color and (
                next_r, next_c) not in visited:
                    neighbours.append([next_r, next_c])
                if not (0 <= next_r < m and 0 <= next_c < n) or grid[next_r][next_c] != search_color:
                    colored_grid[r][c] = color
            for next_r, next_c in neighbours:
                dfs(next_r, next_c, search_color)

        dfs(row, col, colored_grid[row][col])
        return colored_grid

