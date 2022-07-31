import collections
from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        group_by_x = collections.Counter([x for x, y in points])
        max_points = max(group_by_x.values())
        n = len(points)
        for i in range(n):
            for j in range(i+1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                p = y1 - y2
                q = x1 - x2
                if q != 0:
                    line_points = 2
                    for k in range(n):
                        if k != i and k != j:
                            x, y = points[k]
                            if p * (x - x1) == q * (y - y1):
                                line_points += 1
                    max_points = max(max_points, line_points)
        return max_points