import collections
from typing import List


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        d = [[-1] * n for _ in range(m)]
        q = collections.deque()
        for r in range(m):
            for c in range(n):
                if grid[r][c]:
                    q.append([r, c, 0])
                    d[r][c] = 0
        if len(q) == 0 or len(q) == m * n:
            return -1
        max_dist = 0
        while q:
            r, c, dist = q.popleft()
            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                next_r = r + dx
                next_c = c + dy
                if 0 <= next_r < m and 0 <= next_c < n and d[next_r][next_c] == -1:
                    d[next_r][next_c] = 1 + dist
                    q.append([next_r, next_c, 1 + dist])
                    max_dist = max(max_dist, 1 + dist)
        return max_dist
