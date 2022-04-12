from typing import List
from heapq import heappop, heappush


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        hq = []
        for a, b in intervals:
            heappush(hq, [a, 1])
            heappush(hq, [b, -1])
        s = 0
        ans = 0
        while hq:
            _, v = heappop(hq)
            s += v
            ans = max(ans, s)
        return ans
