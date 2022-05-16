import collections


class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        if x == 0 and y == 0:
            return 0
        visited = {(0, 0): [0, 0], (x, y): [1, 0]}  # (x,y) -> [from s|d , distance]
        q = collections.deque([[0, 0, 0, 0], [x, y, 1, 0]])  # (x,y, from s|d, distance)
        while q:
            r, c, f, d = q.popleft()
            for dx, dy in [[2, -1], [2, 1], [1, -2], [1, 2], [-2, -1], [-2, 1], [-1, -2], [-1, 2]]:
                next_xy = (r + dx, c + dy)

                if next_xy not in visited:
                    if next_xy == (x, y):
                        return d + 1
                    else:
                        visited[next_xy] = [f, d + 1]
                        q.append([*next_xy, f, d + 1])
                else:
                    nxf, nxd = visited[next_xy]
                    if nxf != f:
                        return nxd + d + 1
        return -1
