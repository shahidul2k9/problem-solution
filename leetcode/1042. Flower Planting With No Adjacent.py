import collections
from typing import List


class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        color = [-1] * (n + 1)
        g = collections.defaultdict(set)
        for u, v in paths:
            g[u].add(v)
            g[v].add(u)
        for u in range(1, n + 1):
            if color[u] == -1:
                for c in range(1, 5):
                    for v in g[u]:
                        if color[v] == c:
                            break
                    else:
                        color[u] = c
                        break
        del color[0]
        return color
