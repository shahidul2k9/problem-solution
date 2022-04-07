from heapq import heappop, heappush
from typing import List


class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        pq = []
        i = 0
        while i < len(nums):
            v = nums[i]
            if not pq or pq[0][0] == v:
                heappush(pq, [v, 1])
            else:
                seq_last_val, seq_len = heappop(pq)
                if seq_last_val + 1 < v:
                    if seq_len < 3:
                        return False
                    continue
                elif seq_last_val + 1 == v:
                    heappush(pq, [v, seq_len + 1])
            i += 1
        while pq:
            _, seq_len = heappop(pq)
            if seq_len < 3:
                return False

        return True
