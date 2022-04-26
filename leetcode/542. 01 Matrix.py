import collections
from typing import List


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        d = [[None] * n for _ in range(m)]
        q = collections.deque()
        for r in range(m):
            for c in range(n):
                if mat[r][c] == 0:
                    q.append([r, c])
                    d[r][c] = 0
        while q:
            r, c = q.popleft()
            for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    if d[nr][nc] == None:
                        d[nr][nc] = d[r][c] + 1
                        q.append([nr, nc])
        return d

