from typing import List


class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        m, k, n = len(mat1), len(mat1[0]), len(mat2[0])
        pm = [[0] * n for _ in range(m)]
        for r in range(m):
            for c in range(n):
                for i in range(k):
                    pm[r][c] += mat1[r][i] * mat2[i][c]
        return pm

