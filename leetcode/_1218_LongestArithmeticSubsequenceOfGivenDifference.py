import collections
from typing import List


class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        sl = collections.defaultdict(int)
        for b in arr:
            a = b - difference
            sl[b] = max(sl[b], sl[a] + 1)
        return max(sl.values())
