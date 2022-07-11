"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""
import collections


class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        interval_map = collections.defaultdict(int)
        for interval_list in schedule:
            for iv in interval_list:
                interval_map[iv.start] += 1
                interval_map[iv.end] -= 1
        overlap_count = 0
        prev_start = None
        free_time_intervals = []
        for key in sorted(interval_map.keys()):
            overlap_count += interval_map[key]
            if overlap_count == 0:
                prev_start = key
            else:
                if prev_start != None:
                    free_time_intervals.append(Interval(prev_start, key))
                    prev_start = None
        return free_time_intervals

