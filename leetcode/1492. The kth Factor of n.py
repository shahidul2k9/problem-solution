import math
from heapq import heappush, heappop


class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        hq = []
        for i in range(1, math.floor(math.sqrt(n)) + 1):
            if n % i == 0:
                heappush(hq, -i)
                cmp = n // i
                if cmp != i:
                    heappush(hq, -cmp)
            while len(hq) > k:
                heappop(hq)
        if len(hq) < k:
            return -1
        else:
            return hq[0] * -1
