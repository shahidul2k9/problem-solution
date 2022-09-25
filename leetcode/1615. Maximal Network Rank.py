from typing import List
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        in_degree = [0] * n
        edge_set = {(u, v) for [u, v] in roads}
        for (u, v) in roads:
            in_degree[u] += 1
            in_degree[v] += 1
        max_rank = 0
        for u in range(n):
            for v in range(u + 1, n):
                rank = in_degree[u] + in_degree[v]
                if (u,v) in edge_set or (v,u) in edge_set:
                    rank -= 1
                max_rank = max(max_rank, rank)
        return max_rank