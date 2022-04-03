import bisect
import collections
from heapq import heappop, heappush
from typing import List

from sortedcontainers import SortedList


class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        pq = []
        available_server = SortedList([i for i in range(k)])
        load_counter = collections.defaultdict(int)
        for i, (st, lod) in enumerate(zip(arrival, load)):
            while pq and pq[0][0] <= st:
                _, server_index = heappop(pq)
                available_server.add(server_index)
            if len(available_server) > 0:
                target_index = bisect.bisect(available_server, (i % k) - 1)
                target_server_index = available_server.pop(target_index if target_index < len(available_server) else 0)
                heappush(pq, (st + lod, target_server_index))
                load_counter[target_server_index] += 1
        max_value = max(load_counter.values())
        return [key for key, v in load_counter.items() if v == max_value]
