import collections
from typing import List


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        routes = list(map(set, routes))
        g = collections.defaultdict(set)
        bus_count = len(routes)
        for u, r1 in enumerate(routes):
            for v in range(u + 1, bus_count):
                r2 = routes[v]
                if any(s in r2 for s in r1):
                    g[u].add(v)
                    g[v].add(u)

        target_bus = set()
        seen_bus = set()
        q = collections.deque()
        for b, r in enumerate(routes):
            if target in r:
                target_bus.add(b)
            if source in r:
                seen_bus.add(b)
                q.append((b, 1))

        while q:
            u, d = q.popleft()
            if u in target_bus:
                return d
            for v in g[u]:
                if v not in seen_bus:
                    seen_bus.add(v)
                    q.append((v, d + 1))
        return -1
