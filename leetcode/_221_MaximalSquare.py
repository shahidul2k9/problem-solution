from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        dp = {}
        m, n = len(matrix), len(matrix[0])

        def findMaxSquare(r, c):
            if (r, c) in dp:
                return dp[(r, c)]
            elif 0 <= r < m and 0 <= c < n:
                if matrix[r][c] == "1":
                    sideLength = 1 + min(findMaxSquare(r, c + 1), findMaxSquare(r + 1, c), findMaxSquare(r + 1, c + 1))
                else:
                    sideLength = 0

                dp[(r, c)] = sideLength
                return sideLength
            else:
                return 0

        maxSideLength = 0
        for r in range(m):
            for c in range(n):
                maxSideLength = max(maxSideLength, findMaxSquare(r, c))
        return maxSideLength ** 2
