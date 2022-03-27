import collections
from typing import List


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        g = [set() for _ in range(n)]
        for x, y in edges:
            g[x].add(y)
            g[y].add(x)
        q = collections.deque()
        for i in range(n):
            if len(g[i]) == 1:
                q.append(i)

        rn = n
        while rn > 2:
            ln = len(q)
            rn = rn - ln
            i = 0
            while i < ln:
                u = q.popleft()
                for v in g[u]:
                    g[v].remove(u)
                    if len(g[v]) == 1:
                        q.append(v)
                i = i + 1
        if n == 1:
            return [0]
        else:
            return list(q)
