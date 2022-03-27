import collections
from heapq import heappop, heappush
from typing import List


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        g = collections.defaultdict(list)
        for i, (u, v) in enumerate(edges):
            p = succProb[i]
            g[u].append((v, p))
            g[v].append((u, p))
        pd = [0] * n
        pd[start] = 1
        q = [(-1, start)]
        while q:
            (p, u) = heappop(q)
            p = p * -1
            for (v, ep) in g[u]:
                pv = p * ep
                if pv > pd[v]:
                    heappush(q, (-pv, v))
                    pd[v] = pv
        return pd[end]
