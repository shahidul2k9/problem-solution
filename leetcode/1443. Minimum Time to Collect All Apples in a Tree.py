import collections
from typing import List


class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        graph = collections.defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)
        visited = set()
        apple_edges = set()
        parent = [i for i in range(n)]

        def dfs(u: int):
            visited.add(u)
            if hasApple[u]:
                y = u
                while parent[y] != y and not (y, parent[y]) in apple_edges:
                    apple_edges.add((y, parent[y]))
                    y = parent[y]
            for v in graph[u]:
                if v not in visited:
                    parent[v] = u
                    dfs(v)

        dfs(0)
        return 2 * len(apple_edges)
