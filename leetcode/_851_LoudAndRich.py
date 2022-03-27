from typing import List


class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        rg = [set() for _ in range(n)]
        for u, v in richer:
            rg[v].add(u)

        lq = {}
        def dfs(v):
            if v in lq:
                return lq[v]
            least_quiet = v
            for u in rg[v]:
                y = dfs(u)
                if quiet[least_quiet] > quiet[y]:
                    least_quiet = y
            lq[v] = least_quiet
            return least_quiet
        lq_seq = []
        for v in range(n):
            lq_seq.append(dfs(v))
        return lq_seq
