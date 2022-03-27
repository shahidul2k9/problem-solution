from heapq import heappush, heappop
from typing import List


class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        mq = []
        for n in nums:
            heappush(mq, (len(n),n))
            if len(mq) > k:
                heappop(mq)
        return heappop(mq)[1]
