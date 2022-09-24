class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        par = [p for p in range(26)]

        def find(u) -> int:
            if par[u] != u:
                par[u] = find(par[u])
            return par[u]

        def union(u, v):
            pu = find(u)
            pv = find(v)
            if pu < pv:
                par[pv] = pu
            else:
                par[pu] = pv

        for x, y in zip(s1, s2):
            u = ord(x) - ord('a')
            v = ord(y) - ord('a')
            union(u, v)
        smallest_base = []
        for ch in baseStr:
            pu = find(ord(ch) - ord('a'))
            smallest_base.append(chr(pu + ord('a')))
        return ''.join(smallest_base)