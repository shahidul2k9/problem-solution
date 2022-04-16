from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])

        def countLessOrEqual(L, midVal, R):
            r = m - 1
            c = 0
            count = 0
            while r >= 0 and c < n:
                if matrix[r][c] > midVal:
                    R = min(R, matrix[r][c])
                    r -= 1
                else:
                    L = max(L, matrix[r][c])
                    count += r + 1
                    c += 1
            return count, L, R

        start = matrix[0][0]
        end = matrix[m - 1][n - 1]
        while start < end:
            mid = (start + end) / 2
            (cn, L, R) = countLessOrEqual(matrix[0][0], mid, matrix[m - 1][n - 1])
            if cn == k:
                return L
            elif cn < k:
                start = R
            else:
                end = L
        return start



