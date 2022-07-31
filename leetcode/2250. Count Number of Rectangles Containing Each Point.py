from bisect import bisect
from typing import List


class Solution:
    def countRectangles(self, rectangles: List[List[int]], points: List[List[int]]) -> List[int]:
        rectangle_group = [[] for _ in range(101)]
        for x, y in rectangles:
            rectangle_group[y].append(x)
        for y in range(101):
            rectangle_group[y].sort()
        count = [0] * len(points)
        for i, [px, py] in enumerate(points):
            for y in range(py, 101):
                count[i] += len(rectangle_group[y]) - bisect.bisect_right(rectangle_group[y], px - 1)
        return count


