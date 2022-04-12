from collections import defaultdict
from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        connected_components = 0
        graph = defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)
        seen = set()
        for s in range(n):
            if s not in seen:
                connected_components += 1
                stack = [s]
                seen.add(s)
                while stack:
                    u = stack.pop()
                    for v in graph[u]:
                        if v not in seen:
                            stack.append(v)
                            seen.add(v)
        return connected_components
