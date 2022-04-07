from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        minimum_removal = 0
        a, b = intervals[0]
        for i in range(1,len(intervals)):
            c,d = intervals[i]
            if b > c:
                minimum_removal += 1
            else:
                a,b = c,d
        return minimum_removal
