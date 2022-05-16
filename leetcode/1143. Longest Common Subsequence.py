class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[-1] * n for _ in range(m)]

        def lcs(i, j) -> int:
            if i >= m or j >= n:
                return 0
            elif dp[i][j] != -1:
                return dp[i][j]
            else:
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + lcs(i + 1, j + 1)
                else:
                    dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1))
                return dp[i][j]

        return lcs(0, 0)
