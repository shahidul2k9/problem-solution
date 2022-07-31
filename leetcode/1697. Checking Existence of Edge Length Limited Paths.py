from typing import List


class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        par = [i for i in range(n)]

        def find_parent(u) -> int:
            if par[u] != u:
                par[u] = find_parent(par[u])
            return par[u]

        def union(u, v):
            par[find_parent(v)] = find_parent(u)

        edgeList.sort(key=lambda x: x[2])
        sorted_quries = [[u, v, w, index] for index, (u, v, w) in enumerate(queries)]
        sorted_quries.sort(key=lambda x: x[2])

        index = 0
        answers = [False] * len(queries)
        for i, (u, v, w, query_index) in enumerate(sorted_quries):
            while index < len(edgeList) and edgeList[index][2] < w:
                union(edgeList[index][0], edgeList[index][1])
                index += 1
            pu = find_parent(u)
            pv = find_parent(v)
            answers[query_index] = (pu == pv)
        return answers


