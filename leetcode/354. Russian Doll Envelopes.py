from typing import List
import bisect
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key = lambda x : (x[0], -x[1]))
        dp = []
        lis = 0
        for (a, b) in envelopes:
            insertion_index = bisect.bisect_left(dp, b)
            if insertion_index == len(dp):
                dp.append(b)
            else:
                dp[insertion_index] = b
            lis = max(lis, insertion_index + 1)
        return lis