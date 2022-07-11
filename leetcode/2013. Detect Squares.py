import collections
from typing import List


class DetectSquares:

    def __init__(self):
        self.point_count = collections.defaultdict(int)

    def add(self, point: List[int]) -> None:
        self.point_count[tuple(point)] += 1

    def count(self, point: List[int]) -> int:
        x1, y1 = point
        squares = 0
        for x3, y3 in self.point_count.keys():
            if abs(x1 - x3) == abs(y1 - y3) and abs(x1 - x3) > 0:
                x2, y2 = x3, y1
                x4, y4 = x1, y3
                p2_count = self.point_count.get((x2, y2), 0)
                p3_count = self.point_count.get((x3, y3), 0)
                p4_count = self.point_count.get((x4, y4), 0)
                squares += (p2_count * p3_count * p4_count)

        return squares

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)