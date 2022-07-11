import collections
from heapq import heappush, heappop
from typing import List


class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        n = len(scores)
        g = collections.defaultdict(set)
        for u, v in edges:
            g[u].add(v)
            g[v].add(u)
        pq_list = [[] for _ in range(n)]

        def heap_push(pq, s, index):
            heappush(pq, [s, v])
            if len(pq) > 3:
                heappop(pq)

        for u in range(n):
            for v in g[u]:
                heap_push(pq_list[u], scores[v], v)

        for u in range(n):
            pq_list[u].sort(reverse=True, key=lambda x: x[0])

        def add_to_path(path, pq):
            for _, x in pq:
                if x not in path:
                    path.add(x)
                    break

        optimal_path_score = -1
        for u, v in edges:
            path = {u, v}
            add_to_path(path, pq_list[u])
            add_to_path(path, pq_list[v])
            if len(path) == 4:
                optimal_path_score = max(optimal_path_score, sum(scores[x] for x in path))
            path = {u, v}
            add_to_path(path, pq_list[v])
            add_to_path(path, pq_list[u])
            if len(path) == 4:
                optimal_path_score = max(optimal_path_score, sum(scores[x] for x in path))
        return optimal_path_score




