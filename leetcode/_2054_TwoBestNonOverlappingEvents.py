import bisect
from typing import List


class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        N = len(events)
        events.sort(key=lambda x: x[1])
        max_profit = [events[0][2]] * N

        for i in range(1, N):
            max_profit[i] = max(max_profit[i - 1], events[i][2])

        ans = 0
        for i, (s, e, p) in enumerate(events):
            smaller_event_index = bisect.bisect_right(events, s - 1, key=lambda x: x[1]) - 1
            if smaller_event_index >= 0:
                ans = max(ans, max_profit[smaller_event_index] + p)
            else:
                ans = max(ans, p)
        return ans
