import collections
from typing import List


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def squared_distance(a, b):
            x1, y1 = a
            x2, y2 = b
            return (x1 - x2) ** 2 + (y1 - y2) ** 2

        boomerangs_count = 0
        for i in range(len(points)):
            dis_count = collections.defaultdict(int)
            for j in range(len(points)):
                if j != i:
                    d = squared_distance(points[i], points[j])
                    dis_count[d] += 1

            for n in dis_count.values():
                boomerangs_count += n * (n - 1)
        return boomerangs_count
