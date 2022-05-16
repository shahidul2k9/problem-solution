from math import ceil, sqrt


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        squared = set()
        squared_seq = []
        for n in range(0, ceil(sqrt((1 << 31) - 1))):
            v = n * n
            squared.add(v)
            squared_seq.append(v)
        for a_squared in squared_seq:
            if a_squared <= c:
                if (c - a_squared) in squared:
                    return True
            else:
                return False
        return False

