from functools import lru_cache


class Solution:

    def knightDialer(self, n: int) -> int:
        next_digit = [
            [4, 6],
            [6, 8],
            [7, 9],
            [8, 4],
            [3, 9, 0],
            [],
            [1, 7, 0],
            [2, 6],
            [1, 3],
            [2, 4],
        ]

        @lru_cache(maxsize=None)
        def count_move(rem_n, digit) -> int:
            if rem_n == 1:
                return 1
            else:
                moves = 0
                for nd in next_digit[digit]:
                    moves += count_move(rem_n - 1, nd)
                return moves % (10 ** 9 + 7)

        moves = 0
        for d in range(10):
            moves += count_move(n, d)
        return moves % (10 ** 9 + 7)