from heapq import heappush, heappop
from typing import List


class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        available_server_queue = []
        unavailable_server_queue = []
        server_index = [0] * len(tasks)
        for si, sw in enumerate(servers):
            heappush(available_server_queue, (sw, si))
        clock = 0
        for ti, txt in enumerate(tasks):
            clock = max(clock, unavailable_server_queue[0][0] if not available_server_queue else ti)
            while unavailable_server_queue and clock >= unavailable_server_queue[0][0]:
                _, si = heappop(unavailable_server_queue)
                heappush(available_server_queue, (servers[si], si))
            _, si = heappop(available_server_queue)
            server_index[ti] = si
            heappush(unavailable_server_queue, (clock + txt, si))
            #clock = clock + 1 if clock == ti else clock
        return server_index
