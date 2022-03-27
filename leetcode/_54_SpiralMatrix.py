class Solution(object):

    def spiralOrder(self, matrix):
        ddxy = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ddlu = [(1, 0, 0, 0), (0, 0, 0, -1), (0, -1, 0,0), (0, 0, 1, 0)]
        R, C = len(matrix), len(matrix[0])
        N = R * C
        lr, ur, lc, uc = 0, R-1, 0, C-1
        spl = []
        d = 0
        nc = 1
        spl.append(matrix[0][0])
        r, c = 0, 0
        while nc < N:
            dr, dc = ddxy[d]
            while lr <= r + dr <= ur and lc <= c + dc <= uc:
                r = r + dr
                c = c + dc
                spl.append(matrix[r][c])
                nc += 1
               # print(spl)
            lr, ur, lc, uc = (lr + ddlu[d][0], ur + ddlu[d][1], lc + ddlu[d][2], uc + ddlu[d][3])
            d = (d + 1) % 4
        return spl