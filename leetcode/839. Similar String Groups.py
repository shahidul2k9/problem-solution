from typing import List


class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        par = [p for p in range(n)]

        def find_parent(u) -> int:
            if par[u] == u:
                return u
            else:
                par_u = find_parent(par[u])
                par[u] = par_u
                return par_u

        def union(u, v):
            pu = find_parent(u)
            pv = find_parent(v)
            if pu != pv:
                par[pu] = pv

        for i in range(n):
            for j in range(i + 1, n):
                miss_match = []
                for k in range(len(strs[i])):
                    if strs[i][k] != strs[j][k]:
                        miss_match.append(k)
                    if len(miss_match) > 2:
                        break
                else:
                    if len(miss_match) == 0 or (
                            len(miss_match) == 2 and strs[i][miss_match[0]] == strs[j][miss_match[-1]] and strs[i][
                        miss_match[-1]] == strs[j][miss_match[0]]):
                        union(i, j)
        s = set()
        for u in range(n):
            s.add(find_parent(u))
        return len(s)
