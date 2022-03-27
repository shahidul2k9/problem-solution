import collections
from typing import List


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        bk = collections.defaultdict(list)
        for w in words:
            it = iter(w)
            bk[next(it)].append(it)
        match_count = 0
        for c in s:
            matched_words = bk[c]
            bk[c] = []
            for wit in matched_words:
                nx_ch = next(wit, None)
                if nx_ch:
                    bk[nx_ch].append(wit)
                else:
                    match_count += 1
        return match_count
