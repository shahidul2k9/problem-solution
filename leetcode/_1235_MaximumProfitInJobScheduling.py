import bisect
from typing import List


class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        N = len(startTime)
        jobs = [(startTime[i], endTime[i], profit[i]) for i in range(N)]
        jobs.sort(key=lambda x: x[1])
        dp = [None] * N

        def find_max_profit(idx):
            if idx < 0:
                return 0
            elif dp[idx] != None:
                return dp[idx]
            else:
                (s, e, p) = jobs[idx]
                left_max_index = bisect.bisect(jobs, s, key=lambda x: x[1]) - 1
                dp[idx] = max(find_max_profit(left_max_index) + p, find_max_profit(idx - 1))
                return dp[idx]
        return find_max_profit(N-1)
