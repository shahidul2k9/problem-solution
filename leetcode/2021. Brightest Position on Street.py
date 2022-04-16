from heapq import heappush, heappop, heapify
from typing import List


class Solution:
    def brightestPosition(self, lights: List[List[int]]) -> int:
        pq = []
        for lp, r in lights:
            pq.append([lp - r, 1])
            pq.append([lp + r + 1, -1])

        heapify(pq)
        opt = [float('-inf'), 0]
        cur_val = 0
        while pq:
            # print(pq[0], cur_val)
            lp, lv = heappop(pq)
            cur_val += lv
            opp, opv = opt
            if opv < cur_val:
                opt = [lp, cur_val]
        return opt[0]
