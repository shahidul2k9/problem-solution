class Solution:
    def rotatedDigits(self, n: int) -> int:
        rotate = {0: 0, 1: 1, 2: 5, 3: -1, 4: -1, 5: 2, 6: 9, 7: -1, 8: 8, 9: 6}

        def rotate_number(num):
            val = num
            r_val = 0
            factor = 1
            while val > 0:
                d = val % 10
                val = val // 10
                rd = rotate[d]
                if rd == -1:
                    return -1
                r_val += factor * rd
                factor *= 10
            if r_val != num:
                return r_val
            else:
                return -1

        good_nums = 0
        for i in range(1, n + 1):
            if rotate_number(i) != -1:
                good_nums += 1
        return good_nums
