from heapq import heappop, heappush
from typing import List
import collections


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        g = collections.defaultdict(list)
        for u, v, c in flights:
            g[u].append([v, c])

        d = [float('inf')] * n
        stops = [float('inf')] * n
        d[src] = 0
        stops[src] = 0
        pq = [[0, 0, src]]

        while pq:
            uc, cur_k, u = heappop(pq)
            if u == dst:
                return uc
            if cur_k == k + 1:
                continue
            for v, dw in g[u]:
                if uc + dw < d[v]:
                    d[v] = uc + dw
                    heappush(pq, [uc + dw, cur_k + 1, v])
                    stops[v] = cur_k
                elif cur_k < stops[v]:
                    heappush(pq, [uc + dw, cur_k + 1, v])

        return d[dst] if d[dst] < float('inf') else -1