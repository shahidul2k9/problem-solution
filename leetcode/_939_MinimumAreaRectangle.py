from typing import List


class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        N = len(points)
        point_set = {tuple(p) for p in points}
        min_area = float('inf')
        for i in range(N):
            for j in range(i + 1, N):
                x1, y1 = points[i]
                x2, y2 = points[j]
                if x1 != x2 and y1 != y2 and (x2, y1) in point_set and (x1, y2) in point_set:
                    min_area = min(min_area, abs(x1 - x2) * abs(y1 - y2))
        return min_area if min_area != float('inf') else 0
