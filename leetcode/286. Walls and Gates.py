import collections
from typing import List


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])
        q = collections.deque()
        for r in range(m):
            for c in range(n):
                if rooms[r][c] == 0:
                    q.append([r, c])
        while q:
            r, c = q.popleft()
            dist = rooms[r][c]
            for dr, dc in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and rooms[nr][nc] == 2147483647:
                    rooms[nr][nc] = 1 + dist
                    q.append([nr, nc])
