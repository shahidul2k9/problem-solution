from typing import List


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def find_parent(u) -> int:
            if par[u] == u:
                return u
            else:
                pu = find_parent(par[u])
                par[u] = pu
                return pu

        def mhd(p1, p2) -> int:
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

        n = len(points)
        par = [i for i in range(n)]

        edges = []
        for i in range(n):
            for j in range(i + 1, n):
                edges.append([i, j, mhd(points[i], points[j])])
        edges.sort(key=lambda e: e[2])
        total_cost = 0
        for u, v, d in edges:
            pu = find_parent(u)
            pv = find_parent(v)
            if pu != pv:
                total_cost += d
                par[pu] = pv
        return total_cost
