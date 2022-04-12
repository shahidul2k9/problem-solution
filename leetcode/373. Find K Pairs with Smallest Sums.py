from heapq import heappush, heappop
from typing import List


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        pq = []
        for i in range(len(nums1)):
            heappush(pq, [nums1[i] + nums2[0], i, 0])
        smp = []
        while k > 0 and pq:
            _, i, j = heappop(pq)
            smp.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heappush(pq, [nums1[i] + nums2[j+1], i, j + 1])
            k -= 1
        return smp