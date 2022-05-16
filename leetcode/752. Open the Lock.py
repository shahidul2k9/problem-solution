import collections
from typing import List


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def adj(com):
            adj_list = []
            for i in range(len(com)):
                d = ord(com[i]) - ord('0')
                for turn in [1, -1]:
                    nd = (d + turn + 10) % 10
                    next_com = com[:i] + chr(nd + ord('0')) + com[i + 1:]
                    adj_list.append(next_com)
            return adj_list

        dead_locked = set(deadends)
        if '0000' in dead_locked:
            return -1
        elif '0000' == target:
            return 0

        q = collections.deque([['0000', 0]])
        seen = {'0000'}

        while q:
            u, dist = q.popleft()
            for v in adj(u):
                if v not in dead_locked and v not in seen:
                    if v == target:
                        return dist + 1
                    else:
                        q.append([v, dist + 1])
                    seen.add(v)
        return -1


