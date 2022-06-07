import collections
from typing import List


class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        frequency = collections.Counter(arr)
        removed = 0
        for i, fc in enumerate(sorted(frequency.values(), reverse=True)):
            removed += fc
            if removed * 2 >= len(arr):
                return i + 1
        return -1

