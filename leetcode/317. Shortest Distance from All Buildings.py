import collections
from typing import List


class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        distances = [[0] * n for _ in range(m)]
        traces = [[0] * n for _ in range(m)]

        def bfs(source_row, source_col, cur_state):
            q = collections.deque([[source_row, source_col]])
            steps = 0
            while q:
                prev_q_len = len(q)
                i = 0
                steps += 1
                while i < prev_q_len:
                    r, c = q.popleft()
                    for dr, dc in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == cur_state:
                            grid[nr][nc] = cur_state - 1
                            q.append([nr, nc])
                            distances[nr][nc] += steps
                            traces[nr][nc] += 1
                    i += 1

        state = 0
        buildings = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    bfs(r, c, state)
                    state -= 1
                    buildings += 1

        shortest_dist = float('inf')
        for r in range(m):
            for c in range(n):
                if grid[r][c] == state and traces[r][c] == buildings:
                    shortest_dist = min(shortest_dist, distances[r][c])
        return shortest_dist if shortest_dist < float('inf') else -1
