from typing import List


class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        left_out_intervals = []
        c, d = toBeRemoved
        for a, b in intervals:
            if b > c and d > a:
                x, y = a, c
                if a < c:
                    left_out_intervals.append([a, c])
                if d < b:
                    left_out_intervals.append([d, b])
            else:
                left_out_intervals.append([a, b])
        return left_out_intervals
