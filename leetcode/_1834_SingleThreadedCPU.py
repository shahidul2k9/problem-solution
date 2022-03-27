from typing import List
from heapq import heappop, heappush


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tp_list = [(dr, i, st) for i, (st, dr) in enumerate(tasks)]
        tp_list.sort(key=lambda x: (x[2], x[1]))
        i = 0
        pq = []
        execution_order = []
        clock = 0
        while i < len(tp_list) or pq:
            if len(pq) == 0:
                clock = max(tp_list[i][2], clock)
            while i < len(tp_list) and tp_list[i][2] <= clock:
                heappush(pq, tp_list[i])
                i += 1
            (dr, exi, st) = heappop(pq)
            execution_order.append(exi)
            clock += dr
        return execution_order
