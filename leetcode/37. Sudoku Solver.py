from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        has_digit = [[[False] * 10 for _ in range(9)] for _ in range(3)]
        dots = []
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    dots.append([r, c])
                else:
                    d = ord(board[r][c]) - ord('0')
                    z = r // 3 * 3 + c // 3
                    has_digit[0][r][d] = has_digit[1][c][d] = has_digit[2][z][d] = True

        def bracktrack(index: int) -> bool:
            if index == len(dots):
                return True
            else:
                r, c = dots[index]
                for d in range(1, 10):
                    z = r // 3 * 3 + c // 3
                    if not (has_digit[0][r][d] or has_digit[1][c][d] or has_digit[2][z][d]):
                        board[r][c] = chr(d + ord('0'))
                        has_digit[0][r][d] = has_digit[1][c][d] = has_digit[2][z][d] = True
                        if bracktrack(index + 1):
                            return True
                        board[r][c] = '.'
                        has_digit[0][r][d] = has_digit[1][c][d] = has_digit[2][z][d] = False
                return False

        bracktrack(0)
        # print(''.join([''.join(row) + '\n' for row in board]))

