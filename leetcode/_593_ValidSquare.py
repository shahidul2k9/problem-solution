from typing import List


class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        points = [p1, p2, p3, p4]
        points.sort()

        def squared_dist(a, b):
            (x1, y1) = a
            (x2, y2) = b
            return (x1 - x2) ** 2 + (y1 - y2) ** 2

        return squared_dist(points[0], points[3]) == squared_dist(points[1], points[2]) \
               and squared_dist(points[0], points[1]) != 0 \
               and squared_dist(points[0], points[1]) == squared_dist(points[0], points[2]) \
               and squared_dist(points[3], points[2]) == squared_dist(points[3], points[1]) \
               and squared_dist(points[0], points[1]) == squared_dist(points[3], points[2])
