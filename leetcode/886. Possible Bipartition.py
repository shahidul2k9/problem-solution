import collections
from typing import List


class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        g = collections.defaultdict(set)
        for u, v in dislikes:
            g[u].add(v)
            g[v].add(u)
        color = [-1 for _ in range(n + 1)]

        def dfs(u, color_idx):
            color[u] = color_idx
            for v in g[u]:
                if color[v] == color_idx:
                    return False
                elif color[v] == -1:
                    if not dfs(v, 1 - color_idx):
                        return False
            return True

        for u in range(1, n + 1):
            if color[u] == -1:
                if not dfs(u, 0):
                    return False
        return True

