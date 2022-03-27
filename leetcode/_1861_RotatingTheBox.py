from typing import List


class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        rotated_box = [['.'] * m for _ in range(n)]
        for r in range(m):
            c = wc = n - 1
            while c >= 0:
                match box[r][c]:
                    case '*':
                        rotated_box[c][m - 1 - r] = '*'
                        wc = c - 1
                    case '#':
                        rotated_box[wc][m - 1 - r] = '#'
                        wc -= 1
                c -= 1

        return rotated_box
