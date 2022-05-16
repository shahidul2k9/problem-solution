class Solution:
    def __init__(self):
        self.dp = [[-1] * 5 for _ in range(51)]

    def count(self, n: int, char_index: int) -> int:
        if n == 1:
            return 1
        elif self.dp[n][char_index] == -1:
            total = 0
            for vi in range(0, char_index + 1):
                total += self.count(n - 1, vi)
            self.dp[n][char_index] = total
        return self.dp[n][char_index]

    def countVowelStrings(self, n: int) -> int:
        ans = 0
        for voul_index in range(5):
            ans += self.count(n, voul_index)
        return ans