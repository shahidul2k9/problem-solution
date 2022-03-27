class _498_DiagonalTraverse(object):
    def findDiagonalOrder(self, mat):
        m = len(mat)
        n = len(mat[0])
        st = []
        d = 0
        for d in range(m + n - 1):
            from_row = True if d < m else False
            r = d if from_row else m - 1
            c = 0 if from_row else d - m + 1
            diagonal = []
            while 0 <= r < m and 0 <= c < n:
                diagonal.append(mat[r][c])
                r = r - 1
                c = c + 1
            if d % 2 == 0:
                st += diagonal
            else:
                st += diagonal[::-1]
        return st
