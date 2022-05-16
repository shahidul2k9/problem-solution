import collections
from typing import List


class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        delta = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        seen = set()
        q = collections.deque()
        r, c = start
        for di in range(4):
            seen.add((r, c, di))
            q.append([r, c, di, 0])

        while q:
            r, c, di, dist = q.popleft()

            aj_r, aj_c = r + delta[di][0], c + delta[di][1]

            if r == destination[0] and c == destination[1]:
                if not (0 <= aj_r < m and 0 <= aj_c < n) or maze[aj_r][aj_c] == 1:
                    return dist

            if not (0 <= aj_r < m and 0 <= aj_c < n) or maze[aj_r][aj_c] == 1:
                for n_d in range(4):
                    n_r, n_c = r + delta[n_d][0], c + delta[n_d][1]
                    if n_d != di and (0 <= n_r < m and 0 <= n_c < n) and maze[n_r][n_c] != 1 and (
                    n_r, n_c, n_d) not in seen:
                        seen.add((n_r, n_c, n_d))
                        q.append([n_r, n_c, n_d, dist + 1])


            elif (aj_r, aj_c, di) not in seen:
                seen.add((aj_r, aj_c, di))
                q.append([aj_r, aj_c, di, dist + 1])
        return -1


