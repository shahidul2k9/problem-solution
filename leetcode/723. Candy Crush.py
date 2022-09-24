class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        m, n = len(board), len(board[0])
        while True:
            replace = False
            for r in range(m):
                for c in range(n - 2):
                    x, y, z = abs(board[r][c]), abs(board[r][c + 1]), abs(board[r][c + 2])
                    if x > 0 and x == y == z:
                        board[r][c] = board[r][c + 1] = board[r][c + 2] = -x
                        replace = True

            for c in range(n):
                for r in range(m - 2):
                    x, y, z = abs(board[r][c]), abs(board[r + 1][c]), abs(board[r + 2][c])
                    if x > 0 and x == y == z:
                        board[r][c] = board[r + 1][c] = board[r + 2][c] = -x
                        replace = True
            if replace:
                for c in range(n):
                    b = u = m - 1
                    while u >= 0:
                        if board[u][c] > 0:
                            board[b][c] = board[u][c]
                            b -= 1
                        u -= 1
                    while b >= 0:
                        board[b][c] = 0
                        b -= 1
            else:
                return board
