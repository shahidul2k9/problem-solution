from typing import List


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[None] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = [piles[i], 0]

        def opt_points(i, j) -> List[int]:
            if dp[i][j] is not None:
                return dp[i][j]
            else:
                left = [x + y for x, y in zip(opt_points(i + 1, j), [0, piles[i]])][::-1]
                right = [x + y for x, y in zip(opt_points(i, j - 1), [0, piles[j]])][::-1]
                if left[0] > right[0]:
                    dp[i][j] = left
                else:
                    dp[i][j] = right
                return dp[i][j]

        alice, bob = opt_points(0, n - 1)
        return alice > bob
