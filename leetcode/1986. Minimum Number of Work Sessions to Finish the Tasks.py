from functools import lru_cache
from typing import List


class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        tasks.sort()
        n = len(tasks)
        all_set = (1 << n) - 1

        @lru_cache(None)
        def min_session(mask: int, capacity: int) -> int:
            nonlocal n, all_set
            if mask == all_set:
                return 0
            else:
                min_session_count = float('inf')
                for i in range(n):
                    if (1 << i) & mask == 0:
                        if tasks[i] <= capacity:
                            min_session_count = min(min_session_count,
                                                    min_session(mask | (1 << i), capacity - tasks[i]))
                        else:
                            min_session_count = min(min_session_count,
                                                    1 + min_session(mask | (1 << i), sessionTime - tasks[i]))
                return min_session_count

        return min_session(0, 0)




