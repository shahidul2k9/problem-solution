from typing import List
from heapq import heappush, heappop, heapify
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        pq = []
        for p, t in classes:
            pq.append([(p/t)-(p+1)/(t+1), p, t])
        heapify(pq)
        for i in range(extraStudents):
            avg, p, t =heappop(pq)
            p += 1
            t += 1
            heappush(pq, [(p/t)-(p+1)/(t+1), p, t])
        avg_sum = 0
        while pq:
            _, p ,t = heappop(pq)
            avg_sum += p/t
        return avg_sum / len(classes)