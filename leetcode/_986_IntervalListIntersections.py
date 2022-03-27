from typing import List


class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = j = 0
        intersection_list = []
        while i < len(firstList) and j < len(secondList):
            a, b = firstList[i]
            c, d = secondList[j]
            if b >= c and d >= a:
                intersection_list.append([max(a, c), min(b, d)])
            if b < d:
                i += 1
            else:
                j += 1
        return intersection_list
