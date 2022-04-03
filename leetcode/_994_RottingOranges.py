import collections
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        q = collections.deque()
        fresh_fruit_count = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 2:
                    q.append([r, c])
                    grid[r][c] = 0
                elif grid[r][c] == 1:
                    fresh_fruit_count += 1

        min_minutes = 0
        while q and fresh_fruit_count > 0:
            min_minutes += 1
            previous_q_len = len(q)
            for i in range(previous_q_len):
                r, c = q.popleft()
                for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1:
                        q.append([nr, nc])
                        grid[nr][nc] = 0
                        fresh_fruit_count -= 1

        if fresh_fruit_count > 0:
            return -1
        else:
            return min_minutes
