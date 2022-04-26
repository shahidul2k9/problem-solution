from typing import List


class Solution:
    def findRLEArray(self, encoded1: List[List[int]], encoded2: List[List[int]]) -> List[List[int]]:
        i = 0
        j = 0
        enc = []
        while i < len(encoded1) and j < len(encoded2):
            v1, f1 = encoded1[i]
            v2, f2 = encoded2[j]
            f = min(f1, f2)
            v = v1 * v2
            if not enc or enc[-1][0] != v:
                enc.append([v, f])
            else:
                enc[-1][1] += f

            encoded1[i][1] -= f
            encoded2[j][1] -= f
            if encoded1[i][1] == 0:
                i += 1
            if encoded2[j][1] == 0:
                j += 1
        return enc
