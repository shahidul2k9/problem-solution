from collections import defaultdict


class TicTacToe:

    def __init__(self, n: int):
        self.n = n
        self.pl1 = [defaultdict(int), defaultdict(int), [0, 0]]
        self.pl2 = [defaultdict(int), defaultdict(int), [0, 0]]

    def move(self, row: int, col: int, player: int) -> int:
        pl = self.pl1 if player == 1 else self.pl2
        n = self.n
        r = pl[0]
        c = pl[1]
        d = pl[2]
        r[row] += 1
        c[col] += 1
        if row == col:
            d[0] += 1
        if row + col == n - 1:
            d[1] += 1
        for cn in r.values():
            if cn == n:
                return player
        for cn in c.values():
            if cn == n:
                return player
        if d[0] == n or d[1] == n:
            return player
        return 0

# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)