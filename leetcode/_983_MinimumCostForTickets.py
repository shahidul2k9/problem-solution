from bisect import bisect
from functools import lru_cache
from typing import List


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        @lru_cache
        def min_cost(s):
            if s >= len(days):
                return 0
            else:
                lowest_cost = float('inf')
                for i, d in enumerate([1, 7, 30]):
                    next_start = bisect(days, days[s] + d - 1, lo=s)
                    lowest_cost = min(costs[i] + min_cost(next_start), lowest_cost)
                return lowest_cost

        return min_cost(0)
