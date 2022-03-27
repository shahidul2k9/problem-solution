from typing import List


class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        R, C = len(matrix), len(matrix[0])
        ones_square = 0
        for r in range(0, R):
            for c in range(0, C):
                if r != 0 and c != 0 and matrix[r][c] != 0:
                    matrix[r][c] = min(matrix[r - 1][c], matrix[r][c - 1], matrix[r - 1][c - 1]) + 1
                ones_square += matrix[r][c]
        return ones_square
