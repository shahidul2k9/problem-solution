import collections


class Solution:
    def findLeastNumOfUniqueInts(self, arr: list[int], k: int) -> int:
        fc = collections.defaultdict(int)
        for key in arr:
            fc[key] = fc[key] + 1
        seq = list(fc.items())
        seq.sort(key=lambda t: t[1])
        i = 0
        while k > 0 and i < len(seq):
            numKey, f = seq[i]
            if f <= k:
                del fc[numKey]
                k -= f
                i += 1
            else:
                break
        return len(fc)
