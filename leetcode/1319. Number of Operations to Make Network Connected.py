from typing import List


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        par = [u for u in range(n)]

        def find(u) -> int:
            if par[u] == u:
                return u
            else:
                p = find(par[u])
                par[u] = p
                return p

        def union(u, v):
            pu = find(u)
            pv = find(v)
            par[pu] = pv

        if len(connections) < n - 1:
            return -1
        else:
            already_connected_edges = 0
            for u, v in connections:
                pu = find(u)
                pv = find(v)
                if pu != pv:
                    union(pu, pv)
                    already_connected_edges += 1
            return n - 1 - already_connected_edges


