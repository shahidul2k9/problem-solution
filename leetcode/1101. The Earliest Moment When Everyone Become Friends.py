from typing import List


class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        logs.sort()
        par = [u for u in range(n)]

        def find_parent(u) -> int:
            if par[u] == u:
                return u
            else:
                pu = find_parent(par[u])
                par[u] = pu
                return pu

        min_t = 0
        group = n
        for t, u, v in logs:
            if group == 1:
                return min_t
            else:
                pu = find_parent(u)
                pv = find_parent(v)
                if pu != pv:
                    par[pu] = pv
                    min_t = t
                    group -= 1
        return min_t if group == 1 else -1

