import collections
import heapq
from typing import List


class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        g = collections.defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))

        d = [float('inf') for _ in range(n + 1)]
        d[n] = 0
        pq = [(0, n)]

        while pq:
            cd, u = heapq.heappop(pq)
            for v, w in g[u]:
                if cd + w < d[v]:
                    d[v] = cd + w
                    heapq.heappush(pq, (d[v], v))

        way = {1: 1}

        def dfs(v):
            if v in way:
                return way[v]
            tw = 0
            for u, w in g[v]:
                if d[u] > d[v]:
                    tw = (tw + dfs(u)) % 1000000007
            way[v] = tw
            return tw

        return dfs(n)
