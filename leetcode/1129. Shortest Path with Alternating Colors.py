import collections
from typing import List


class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        graph = dict()
        RED = 0
        BLUE = 1
        for u in range(n):
            graph.setdefault(u, [set(), set()])

        for u, v in redEdges:
            graph[u][RED].add(v)

        for u, v in blueEdges:
            graph[u][BLUE].add(v)

        dist = [[float('inf')] * n for _ in range(2)]

        dist[RED][0] = dist[BLUE][0] = 0
        q = collections.deque([[0, RED], [0, BLUE]])
        visited = set([(0, RED), (0, BLUE)])
        while q:
            u, color_u = q.popleft()
            if color_u == BLUE:
                color_v = RED
            else:
                color_v = BLUE

            for v in graph[u][color_v]:
                if (v, color_v) not in visited:
                    dist[color_v][v] = dist[color_u][u] + 1
                    visited.add((v, color_v))
                    q.append([v, color_v])
        shortest_dist = [min(dist[RED][i], dist[BLUE][i]) for i in range(n)]
        for u in range(n):
            if shortest_dist[u] == float('inf'):
                shortest_dist[u] = -1
        return shortest_dist
