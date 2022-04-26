import collections
from typing import List


class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        m, n = len(room), len(room[0])
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        cleaned_rooms = {(0, 0)}
        visited = {(0, 0, 0)}
        q = collections.deque([[0, 0, 0]])
        while q:
            r, c, d = q.popleft()
            i = 0
            while i < 4:
                dr, dc = directions[d]
                next_r, next_c, next_d = r + dr, c + dc, d
                if not (0 <= next_r < m and 0 <= next_c < n) or room[next_r][next_c] == 1:
                    d = (d + 1) % len(directions)
                else:
                    if (next_r, next_c, next_d) not in visited:
                        q.append([next_r, next_c, next_d])
                        visited.add((next_r, next_c, next_d))
                        if (next_r, next_c) not in cleaned_rooms:
                            cleaned_rooms.add((next_r, next_c))
                    break
                i += 1
        return len(cleaned_rooms)
