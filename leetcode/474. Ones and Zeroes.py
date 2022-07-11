from functools import lru_cache
from typing import List


class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        ones = []
        for s in strs:
            ones.append(s.count('1'))

        @lru_cache(maxsize=None)
        def max_subset(x, y, pos) -> int:
            if pos < 0:
                return 0
            else:
                on = ones[pos]
                off = len(strs[pos]) - on
                max_sz = max_subset(x, y, pos - 1)
                if x - off >= 0 and y - on >= 0:
                    max_sz = max(max_sz, max_subset(x - off, y - on, pos - 1) + 1)
                return max_sz

        return max_subset(m, n, len(strs) - 1)
