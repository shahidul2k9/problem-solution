from typing import List


class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        rg = [set() for _ in range(n + 1)]
        mt = {}
        for v, v in relations:
            rg[v].add(v)

        def dfs(v):
            if v in mt:
                return mt[v]
            ut = 0
            for u in rg[v]:
                ut = max(dfs(u), ut)

            mt[v] = ut + time[v - 1]
            return mt[v]

        max_time = 0
        for v in range(1, n + 1, 1):
            max_time = max(max_time, dfs(v))
        return max_time
