from typing import List


class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m, n = len(board), len(board[0])
        next_state = [row[::] for row in board]
        dxy = [[0, 1], [1, 0], [0, -1], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]

        def reveal(r, c):

            adj_revealed_mine = adj_unrevealed_mine = 0
            for dx, dy in dxy:
                nr, nc = r + dx, c + dy
                if 0 <= nr < m and 0 <= nc < n:
                    if next_state[nr][nc] == 'X':
                        adj_revealed_mine += 1
                    if next_state[nr][nc] == 'M':
                        adj_unrevealed_mine += 1
            total_mines = adj_revealed_mine + adj_unrevealed_mine
            if total_mines == 0:
                next_state[r][c] = 'B'
                for dx, dy in dxy:
                    nr, nc = r + dx, c + dy
                    if 0 <= nr < m and 0 <= nc < n and next_state[nr][nc] == 'E':
                        reveal(nr, nc)
            else:
                next_state[r][c] = str(total_mines)

        cr, cc = click
        if board[cr][cc] == 'M':
            next_state[cr][cc] = 'X'
        else:
            reveal(cr, cc)
        return next_state

