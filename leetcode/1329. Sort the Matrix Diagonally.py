import collections
from typing import List


class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        dm = collections.defaultdict(list)
        m, n = len(mat), len(mat[0])
        sorted_mat = [[0] * n for _ in range(m)]
        for r in range(m):
            for c in range(n):
                idx = r - c
                dm[idx].append(mat[r][c])
        for d in dm.values():
            d.sort()
        for k, d in dm.items():
            if k <= 0:
                r = 0
                c = abs(k)
            else:
                r = k
                c = 0
            for val in d:
                sorted_mat[r][c] = val
                r += 1
                c += 1
        return sorted_mat
