from typing import List


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda iv: (iv[0], -iv[1]))
        removed = 0
        for i, (a, b) in enumerate(intervals):
            if i == 0 or not (c <= a and b <= d):
                c, d = a, b
            else:
                removed += 1
        return len(intervals) - removed
