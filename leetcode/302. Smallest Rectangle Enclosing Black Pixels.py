from typing import List


class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        left, right = y, y
        top, bottom = x, x
        visited = {(x, y)}
        R, C = len(image), len(image[0])
        def dfs(r, c):
            nonlocal left, right, top, bottom
            for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                nx = r + dx
                ny = c + dy
                if 0 <= nx < R and 0 <= ny < C and image[nx][ny] == '1' and (nx, ny) not in visited:
                    left = min(left, ny)
                    right= max(right, ny)
                    top = min(top, nx)
                    bottom = max(bottom, nx)
                    visited.add((nx, ny))
                    dfs(nx, ny)
        dfs(x, y)
        return (right - left + 1) * (bottom - top + 1)