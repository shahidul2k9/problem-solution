import collections
from typing import List


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        g = collections.defaultdict(set)
        n = len(stones)
        for u in range(n):
            for v in range(u+1, n):
                r1, c1 = stones[u]
                r2, c2 = stones[v]
                if r1 == r2 or c1 == c2:
                    g[u].add(v)
                    g[v].add(u)
        visited = set()
        def dfs(u):
            visited.add(u)
            for v in g[u]:
                if v not in visited:
                    dfs(v)
        connected_components = 0
        for u in range(n):
            if u not in visited:
                dfs(u)
                connected_components += 1
        return n - connected_components