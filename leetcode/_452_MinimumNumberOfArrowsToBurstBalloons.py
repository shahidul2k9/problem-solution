from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        minimum_arrays = 1
        a, b = points[0]
        for c, d in points:
            if b >= c:
                a, b = max(a, c), min(b, d)
            else:
                a, b = c, d
                minimum_arrays += 1
        return minimum_arrays