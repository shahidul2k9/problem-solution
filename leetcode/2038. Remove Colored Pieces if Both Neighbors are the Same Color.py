class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        alice_moves = bob_moves = 0
        mover = colors[0]
        n = 1
        for i in range(1, len(colors)):
            if mover != colors[i]:
                if mover == 'A':
                    alice_moves += max(n - 2, 0)
                else:
                    bob_moves += max(n - 2, 0)
                n = 1
                mover = colors[i]
            else:
                n += 1
        if mover == 'A':
            alice_moves += max(n - 2, 0)
        else:
            bob_moves += max(n - 2, 0)
        return alice_moves > bob_moves

