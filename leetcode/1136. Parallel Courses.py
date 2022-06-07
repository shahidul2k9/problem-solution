import collections
from typing import List


class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        inf = 2 * n
        ind = [0] * (n + 1)
        dist = [inf] * (n + 1)
        g = collections.defaultdict(set)
        for u, v in relations:
            ind[v] += 1
            g[u].add(v)

        q = collections.deque()
        for u in range(1, n + 1):
            if ind[u] == 0:
                q.append(u)
                dist[u] = 1
        while q:
            u = q.popleft()
            for v in g[u]:
                ind[v] -= 1
                if ind[v] == 0:
                    q.append(v)
                    dist[v] = dist[u] + 1
        max_dist = 0
        for u in range(1, n + 1):
            max_dist = max(max_dist, dist[u])
        return -1 if max_dist == inf else max_dist