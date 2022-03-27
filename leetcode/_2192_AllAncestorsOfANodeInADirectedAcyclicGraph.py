import collections
from typing import List


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        d = [0 for _ in range(n)]
        g = [[] for _ in range(n)]
        p = [set() for _ in range(n)]
        for u, v in edges:
            d[v] += 1
            g[u].append(v)
        q = collections.deque()
        for i in range(n):
            if d[i] == 0:
                q.append(i)
        while q:
            u = q.popleft()
            for v in g[u]:
                d[v] -= 1
                p[v].add(u)
                for x in p[u]:
                    p[v].add(x)
                if d[v] == 0:
                    q.append(v)

        for i in range(n):
            p[i] = sorted(p[i])
        return p

print(Solution().getAncestors(8, [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]))