from collections import defaultdict
from heapq import heappop, heappush, heapify
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        task_frequency = defaultdict(int)
        for task in tasks:
            task_frequency[task] += 1
        q = []
        waiting_q = []
        for frequency in task_frequency.values():
            q.append(-frequency)
        heapify(q)
        elapsed_time = 0
        clock = 0
        while q or waiting_q:
            while waiting_q and waiting_q[0][0] <= clock:
                _, nf = heappop(waiting_q)
                heappush(q, nf)
            if not q:
                release_time, nf = heappop(waiting_q)
                move_time = release_time - clock
                elapsed_time += move_time
                clock += move_time
                f = -nf
            else:
                f = -1 * heappop(q)

            elapsed_time += 1
            clock += 1
            if f > 1:
                heappush(waiting_q, [clock + n, -(f - 1)])

        return elapsed_time

