import collections
from collections import Counter
from heapq import heappush, heappop


class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        frequency = Counter(s)
        max_pq = []
        for ch, f in frequency.items():
            heappush(max_pq, [-f, ch])
        index = 0
        chars = []
        waiting_pool = collections.deque()
        while max_pq:

            f, ch = heappop(max_pq)
            chars.append(ch)
            if f < -1:
                waiting_pool.append([f + 1, ch, index])
            index += 1
            if waiting_pool and index - waiting_pool[0][2] >= k:
                heappush(max_pq, waiting_pool.popleft()[0:2])

        if len(chars) == len(s):
            return ''.join(chars)
        else:
            return ''

