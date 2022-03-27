import collections
from typing import List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        WHITE, GRAY, BLACK = 0, 1, 2
        color = collections.defaultdict(int)

        def dfs(u):
            if color[u] != WHITE:
                return color[u] == BLACK
            color[u] = GRAY
            for v in graph[u]:
                if not dfs(v):
                    return False
            color[u] = BLACK
            return True

        return list(filter(dfs, range(n)))
