class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1, l2, l3 = len(s1), len(s2), len(s3)
        if l1 + l2 != l3:
            return False
        dp = [[None] * (l2 + 1) for _ in range(l1 + 1)]

        def is_interleaving(a, b):
            if a + b >= l3:
                return True
            if a < l1 and b < l2 and dp[a][b] is not None:
                return dp[a][b]
            is_possible = False
            if a < l1 and s1[a] == s3[a + b]:
                is_possible |= is_interleaving(a + 1, b)
            if not is_possible and (b < l2 and s2[b] == s3[a + b]):
                is_possible |= is_interleaving(a, b + 1)
            dp[a][b] = is_possible
            return is_possible

        return is_interleaving(0, 0)
