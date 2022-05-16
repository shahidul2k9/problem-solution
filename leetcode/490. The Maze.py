from typing import List


class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m, n = len(maze), len(maze[0])
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        def has_next(r, c, d) -> bool:
            nr, nc = r + directions[d][0], c + directions[d][1]
            if not (0 <= nr < m and 0 <= nc < n) or maze[nr][nc] == 1:
                return False
            else:
                return True

        visited = set()

        def dfs(r, c, d) -> bool:
            if r == destination[0] and c == destination[1] and not has_next(r, c, d):
                return True

            visited.add((r, c, d))
            if has_next(r, c, d):
                next_directions = [d]
            else:
                next_directions = [0, 1, 2, 3]
                next_directions.remove(d)
            for next_d in next_directions:
                nr, nc = r + directions[next_d][0], c + directions[next_d][1]
                if has_next(r, c, next_d) and (nr, nc, next_d) not in visited:
                    if dfs(nr, nc, next_d):
                        return True
            return False

        for d in range(len(directions)):
            if dfs(start[0], start[1], d):
                return True
        return False


