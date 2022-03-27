from collections import Counter
from itertools import zip_longest


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        w1fc = Counter(word1)
        w2fc = Counter(word2)
        return set(w1fc.keys()) == set(w2fc.keys()) and \
               all(x == y for x, y in
                   zip_longest(sorted(w1fc.values()), sorted(w2fc.values()),
                               fillvalue=0))
