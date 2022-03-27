class Solution(object):
    def generateMatrix(self, n):
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        ddxy = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        lr, ur, lc, uc = 0, n - 1, 0, n - 1
        d = 0
        nc = 1
        r, c = 0, 0
        matrix[r][c] = 1
        while nc < n * n:
            dr, dc = ddxy[d]
            while lr <= r + dr <= ur and lc <= c + dc <= uc:
                r = r + dr
                c = c + dc
                nc += 1
                matrix[r][c] = nc

            if d == 0:
                lr += 1
            elif d == 1:
                uc -= 1
            elif d == 2:
                ur -= 1
            else:
                lc += 1
            d = (d + 1) % 4
        return matrix
