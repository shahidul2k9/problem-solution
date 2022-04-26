from collections import deque
from typing import List


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        cq = deque([0])
        while cq:
            if len(visited) == len(rooms):
                return True
            rn = cq.popleft()
            if rn not in visited:
                visited.add(rn)
                for k in rooms[rn]:
                    cq.append(k)
        return len(rooms) == len(visited)



