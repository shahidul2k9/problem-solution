import collections
from typing import List


class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        active_minute_count = collections.defaultdict(set)
        for id, t in logs:
            active_minute_count[id].add(t)

        uam = [0] * k
        for v in active_minute_count.values():
            if len(v) <= k:
                uam[len(v) - 1] += 1
        return uam
