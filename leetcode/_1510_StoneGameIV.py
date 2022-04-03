class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [None] * (n + 1)
        dp[0] = False
        dp[1] = True

        def can_win(s):
            if dp[s] != None:
                return dp[s]
            else:
                i = 1
                while i * i <= s:
                    if not can_win(s - i * i):
                        break
                    i += 1
                else:
                    dp[s] = False
                    return dp[s]

                dp[s] = True
                return dp[s]

        return can_win(n)
