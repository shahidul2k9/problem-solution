class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        dp = [[None] * n for _ in range(n)]

        def min_insertion(a, b):
            if a >= b:
                return 0
            elif dp[a][b] is not None:
                return dp[a][b]
            else:
                if s[a] == s[b]:
                    dp[a][b] = min_insertion(a + 1, b - 1)
                else:
                    dp[a][b] = min(min_insertion(a + 1, b), min_insertion(a, b - 1)) + 1
                return dp[a][b]

        return min_insertion(0, len(s) - 1)
