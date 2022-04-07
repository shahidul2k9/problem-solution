from typing import List


class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        even_nums = []
        if finalSum & 1 == 0:
            c = 2
            while finalSum > 0 and finalSum - c > c:
                even_nums.append(c)
                finalSum -= c
                c += 2
            if finalSum:
                even_nums.append(finalSum)
        return even_nums
