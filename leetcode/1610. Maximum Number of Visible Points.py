import math
from typing import List


class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        polar_angles = []
        lx, ly = location
        zeros = 0
        for px, py in points:
            if px == lx and py == ly:
                zeros += 1
            else:
                degree = math.degrees(math.atan2(py - ly, px - lx))
                if degree < 0:
                    polar_angles.append(degree + 360)
                else:
                    polar_angles.append(degree)

        polar_angles.sort()

        n = len(polar_angles)
        for theta in polar_angles[:]:
            polar_angles.append(theta + 360)
        lo = hi = 0
        ans = 0
        while hi < len(polar_angles):
            while polar_angles[hi] - polar_angles[lo] > angle or hi - lo + 1 > n:
                lo += 1
            ans = max(ans, hi - lo + 1)
            hi += 1
        return ans + zeros
