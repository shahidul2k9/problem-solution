import collections
from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])

        def find_cluster(r, c):
            seen = {(r, c)}
            q = collections.deque([(r, c)])
            capturable = True
            while q:
                r, c = q.popleft()
                for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n:
                        if board[nr][nc] == 'O' and (nr, nc) not in seen:
                            seen.add((nr, nc))
                            q.append((nr, nc))
                    else:
                        capturable = False
            return seen, capturable

        not_capturable = set()
        for r in range(m):
            for c in range(n):
                if (r, c) not in not_capturable and board[r][c] == 'O':
                    seen, capturable = find_cluster(r, c)
                    if capturable:
                        for x, y in seen:
                            board[x][y] = 'X'
                    else:
                        not_capturable |= seen


