from typing import List


class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        m, n = len(board), len(board[0])
        battle_ships = 0
        for r in range(m):
            for c in range(n):
                if board[r][c] == 'X':
                    if not (r - 1 >= 0 and board[r - 1][c] == 'X') and not (c - 1 >= 0 and board[r][c - 1] == 'X'):
                        battle_ships += 1
        return battle_ships
