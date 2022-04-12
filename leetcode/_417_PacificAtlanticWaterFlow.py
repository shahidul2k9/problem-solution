from collections import deque
from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        M, N = len(heights), len(heights[0])

        def bfs(q):
            s = set(q)
            while q:
                r, c = q.popleft()
                for dr, dc in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                    nr = r + dr
                    nc = c + dc
                    if 0 <= nr < M and 0 <= nc < N and heights[nr][nc] >= heights[r][c] and \
                            (nr, nc) not in s:
                        s.add((nr, nc))
                        q.append((nr, nc))
            return s

        pacific_q = deque()
        atlantic_q = deque()

        for c in range(N):
            pacific_q.append((0, c))
            atlantic_q.append((M - 1, c))
        for r in range(M):
            pacific_q.append((r, 0))
            atlantic_q.append((r, N - 1))

        pacific_cells = bfs(pacific_q)
        atlantic_cells = bfs(atlantic_q)
        return list(map(lambda x: [x[0], x[1]], pacific_cells.intersection(atlantic_cells)))
