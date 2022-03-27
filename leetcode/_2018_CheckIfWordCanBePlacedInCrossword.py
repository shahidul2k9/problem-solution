from typing import List


class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        def attachWord():
            R, C = len(board), len(board[0])
            n = len(word)
            for r in range(R):
                spaces = 0
                for c in range(C):
                    ch = board[r][c]
                    if ch == '#':
                        if spaces == n:
                            return True
                        else:
                            spaces = 0
                    else:
                        if ch == ' ' or (spaces < n and word[spaces] == ch):
                            spaces += 1
                        else:
                            spaces += 2 * n
                if spaces == n:
                    return True

            for c in range(C):
                spaces = 0
                for r in range(R):
                    ch = board[r][c]
                    if ch == '#':
                        if spaces == n:
                            return True
                        else:
                            spaces = 0
                    else:
                        if ch == ' ' or (spaces < n and word[spaces] == ch):
                            spaces += 1
                        else:
                            spaces += 2 * n

                if spaces == n:
                    return True
            return False

        if attachWord():
            return True
        else:
            word = word[::-1]
            return attachWord()

