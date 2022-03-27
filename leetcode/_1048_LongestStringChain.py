from functools import lru_cache
from typing import List


class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        word_set = set(words)

        @lru_cache(maxsize=None)
        def lsc(w):
            mx = 0
            for i in range(len(w)):
                pw = (w[:i] if i > 0 else '') + (w[i + 1:] if i + 1 < len(w) else '')
                if pw in word_set:
                    mx = max(mx, lsc(pw))
            return 1 + mx

        return max(lsc(w) for w in words)


#print(Solution().longestStrChain(["a", "b", "ba", "bca", "bda", "bdca"]))
