class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        points.sort(key=lambda p: p[0] ** 2 + p[1] ** 2)
        closest_points = []
        for i in range(k):
            closest_points.append(points[i])
        return closest_points
