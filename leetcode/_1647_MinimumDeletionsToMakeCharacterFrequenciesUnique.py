import collections
from collections import Counter


class Solution:
    def minDeletions(self, s: str) -> int:
        fl = list(Counter(s).values())

        fl.sort()
        used_fc = collections.defaultdict(int)
        for f in fl:
            used_fc[f] += 1
        dl = 0
        for f in fl:
            if used_fc[f] > 1:
                avf = f
                while avf in used_fc:
                    avf -= 1
                dl += f - avf
                if avf > 0:
                    used_fc[avf] += 1
                used_fc[f] -= 1
        return dl
