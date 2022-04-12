from typing import List


class Solution:
    def longestLine(self, mat: List[List[int]]) -> int:
        M, N = len(mat), len(mat[0])
        max_run = [[None] * N for _ in range(M)]
        max_line = 0
        for r in range(M):
            for c in range(N):

                d = mat[r][c]
                if d > 0:
                    left = max_run[r][c - 1][0] if c > 0 else 0
                    up = max_run[r - 1][c][1] if r > 0 else 0
                    up_left_corner = max_run[r - 1][c - 1][2] if r > 0 and c > 0 else 0
                    up_right_corner = max_run[r - 1][c + 1][3] if r > 0 and c + 1 < N else 0

                    max_run[r][c] = [left + d, up + d, up_left_corner + d, up_right_corner + d]
                    max_line = max(max_line, max(max_run[r][c]))
                else:
                    max_run[r][c] = [0] * 4
        return max_line
