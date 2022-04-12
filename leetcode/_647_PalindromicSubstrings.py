class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        p = [[False] * n for _ in range(n)]
        for i in range(n):
            p[i][i] = True
        pnc = n
        for d in range(1, n):
            for i in range(0, n - d):
                if s[i] == s[i + d] and (d < 2 or p[i + 1][i + d - 1]):
                    p[i][i + d] = True
                    pnc += 1
        return pnc
