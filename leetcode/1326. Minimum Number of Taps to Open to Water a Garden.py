from typing import List


class Interval:
    def __init__(self, left: int, right: int):
        self.left = left
        self.right = right


class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        intervals = [Interval(i - radius, i + radius) for i, radius in enumerate(ranges) if radius > 0]
        intervals.sort(key=lambda iv: -iv.left)

        taps = 0
        location = 0
        while location < n and intervals:
            farthest_right = -1
            while intervals and intervals[-1].left <= location:
                top = intervals.pop()
                farthest_right = max(farthest_right, top.right)
            if location < farthest_right >= 0:
                location = farthest_right
                taps += 1
            else:
                break
        if location >= n:
            return taps
        else:
            return -1