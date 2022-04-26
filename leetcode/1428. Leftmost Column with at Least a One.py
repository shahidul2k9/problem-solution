# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
# class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        m, n = binaryMatrix.dimensions()
        r, c = 0, n - 1
        last_col = -1
        while r < m and c >= 0:
            if binaryMatrix.get(r, c) == 1:
                last_col = c
                c -= 1
            else:
                r += 1
        return last_col
