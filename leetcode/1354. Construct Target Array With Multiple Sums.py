from heapq import heappush, heappop
from typing import List


class Solution:
    def isPossible(self, target: List[int]) -> bool:
        max_heap = []
        s = 0
        for v in target:
            if v > 1:
                heappush(max_heap, -v)
            s += v
        while len(max_heap):
            max_val = -heappop(max_heap)
            if len(max_heap) > 0:
                second_max = -max_heap[0]
            else:
                second_max = 1
            s_complement = s - max_val
            # n <= (mx - 2nd_mx)//s_comp
            if s_complement <= 0:
                return False
            n = max(1, (max_val - second_max) // s_complement)
            removal_val = n * s_complement
            new_max_val = max_val - removal_val
            if new_max_val > 1:
                heappush(max_heap, -new_max_val)
            elif new_max_val <= 0:
                return False
            s -= removal_val
        return True

