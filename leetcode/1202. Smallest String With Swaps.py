import collections
from typing import List


class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        s_seq = list(s)
        par = [u for u in range(n)]
        rank = [0 for _ in range(n)]

        def find(u) -> int:
            if par[u] == u:
                return u
            else:
                pu = find(par[u])
                par[u] = pu
                return pu

        def union(u, v):
            pu = find(u)
            pv = find(v)
            if pu != pv:
                if rank[pu] < rank[pv]:
                    pu, pv = pv, pu
                par[pv] = pu
                rank[pu] += rank[pv]
            return pu

        for u, v in pairs:
            union(u, v)
        group = collections.defaultdict(list)
        for u in range(n):
            group[find(u)].append(u)
        for g, pos_list in group.items():
            char_group = []
            for i in pos_list:
                char_group.append(s[i])
            char_group.sort()
            for gi, i in enumerate(pos_list):
                s_seq[i] = char_group[gi]
        return ''.join(s_seq)
