from typing import List


class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        def is_win(who) -> bool:
            win_seq = who * 3
            for row in board:
                if row == win_seq:
                    return True
            for col_index in range(3):
                if board[0][col_index] + board[1][col_index] + board[2][col_index] == win_seq:
                    return True
            if board[0][0] + board[1][1] + board[2][2] == win_seq:
                return True
            return board[0][2] + board[1][1] + board[2][0] == win_seq

        x_count, o_count = 0, 0
        for r in range(3):
            for c in range(3):
                if board[r][c] == 'X':
                    x_count += 1
                elif board[r][c] == 'O':
                    o_count += 1
        x_win = is_win('X')
        o_win = is_win('O')

        if x_count < o_count or x_count - 1 > o_count:
            return False
        if x_win and o_win:
            return False
        if x_win and x_count <= o_count:
            return False
        if o_win and x_count != o_count:
            return False
        return True

