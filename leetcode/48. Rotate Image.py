from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        r = c = 0
        lr = lc = n - 1
        while r < lr:
            for d in range(lr - r):
                val = matrix[r][lc - d]
                matrix[r][lc - d] = matrix[r + d][c]
                matrix[r + d][c] = matrix[lr][c + d]
                matrix[lr][c + d] = matrix[lr - d][lc]
                matrix[lr - d][lc] = val
            lr -= 1
            lc -= 1
            r += 1
            c += 1


