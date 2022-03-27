class Solution:
    def minSteps(self, s: str, t: str) -> int:
        f = {}
        for c in s:
            c1, c2 = f.get(c, (0, 0))
            f[c] = (c1 + 1, c2)

        for c in t:
            c1, c2 = f.get(c, (0, 0))
            f[c] = (c1, c2 + 1)

        cn = 0
        for c1, c2 in f.values():
            cn += abs(c1 - c2)
        return int(cn / 2)
