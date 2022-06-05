from functools import lru_cache


class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:

        @lru_cache(maxsize=None)
        def probability_staying(rn, r, c) -> float:
            if 0 <= r < n and 0 <= c < n:
                if rn == 0:
                    return 1
                else:
                    p = 0
                    for dx, dy in [[2, 1], [2, -1], [-2, 1], [-2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]:
                        p += probability_staying(rn - 1, r + dx, c + dy) / 8
                    return p
            else:
                return 0

        return probability_staying(k, row, column)