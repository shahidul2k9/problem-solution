import collections
from typing import List


class Solution:
    def closestNode(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        g = collections.defaultdict(set)
        for u, v in edges:
            g[u].add(v)
            g[v].add(u)

        def bfs_find_distance(source):
            d = [-1] * n
            d[source] = 0
            q = collections.deque([source])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if d[v] == -1:
                        d[v] = d[u] + 1
                        q.append(v)
            return d

        def bfs_find_path(source, destination) -> List[int]:
            par = [-1] * n
            par[source] = source
            q = collections.deque([source])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if par[v] == - 1:
                        par[v] = u
                        q.append(v)
            return par

        min_distances_nodes = []
        for u, v, w in query:
            d = bfs_find_distance(w)
            par = bfs_find_path(u, v)
            x = v
            min_dist = d[x]
            min_node = x
            while True:
                x = par[x]
                if d[x] < min_dist:
                    min_dist = d[x]
                    min_node = x
                if par[x] == x:
                    break
            min_distances_nodes.append(min_node)
        return min_distances_nodes