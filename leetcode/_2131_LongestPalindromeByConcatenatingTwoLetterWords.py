from collections import Counter
from typing import List


class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        f = Counter(words)
        max_len = 0
        for w in f.keys():
            while f[w] > 0:
                rw = w[::-1]
                if (w == rw and f[w] > 1) or (w != rw and f[rw] > 0):
                    max_len += 2 * len(w)
                    f[w] -= 1
                    f[rw] -= 1
                else:
                    break
        for w in f.keys():
            if f[w] > 0 and w == w[::-1]:
                max_len += len(w)
                break
        return max_len
