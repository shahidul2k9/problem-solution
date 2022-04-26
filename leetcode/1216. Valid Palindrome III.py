class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        dp = [[None] * n for _ in range(n)]

        def min_del(a, b):
            if a >= b:
                return 0
            elif dp[a][b] is not None:
                return dp[a][b]
            else:
                if s[a] == s[b]:
                    ans = min_del(a + 1, b - 1)
                else:
                    ans = 1 + min(min_del(a + 1, b), min_del(a, b - 1))
                dp[a][b] = ans
                return ans

        return min_del(0, n - 1) <= k

