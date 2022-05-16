class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        pm = collections.defaultdict(list)
        n = len(s)
        for i, ch in enumerate(s):
            pm[ch].append(i)
        dp = [[-1] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1

        # def lower_bound(ch, a, b)-> int:
        #     arr = pm[ch]
        #     low = 0
        #     high = len(arr) - 1
        #     known_index = -1
        #     while low <= high:
        #         mid = (low + high) // 2
        #         if arr[mid] < a:
        #             low = mid + 1
        #         elif arr[mid] > b:
        #             high = mid -1
        #         else:
        #             known_index = mid
        #            high = mid -1
        #     return known_index

        def lps(i, j) -> int:
            if i > j:
                return 0
            elif dp[i][j] != -1:
                return dp[i][j]
            else:
                sub_seq_len = 0
                if s[i] == s[j]:
                    sub_seq_len = 2 + lps(i + 1, j - 1)
                else:
                    sub_seq_len = max(lps(i + 1, j), lps(i, j - 1))
                dp[i][j] = sub_seq_len
                return dp[i][j]

        return lps(0, n - 1)


