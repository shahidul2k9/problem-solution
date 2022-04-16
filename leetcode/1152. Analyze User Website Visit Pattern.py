import collections
from typing import List


class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        utw = collections.defaultdict(list)
        web_set = set()
        for u, t, w in sorted(zip(username, timestamp, website), key=lambda x: x[1]):
            utw[u].append(w)
            web_set.add(w)
        utw_seq = collections.defaultdict(set)

        for u, wl in utw.items():
            for i in range(len(wl)):
                for j in range(i + 1, len(wl)):
                    for k in range(j + 1, len(wl)):
                        utw_seq[u].add((wl[i], wl[j], wl[k]))
        wl = list(sorted(web_set))
        uu = 0
        pattern = None

        for w1 in wl:
            for w2 in wl:
                for w3 in wl:
                    t = (w1, w2, w3)
                    n = 0
                    for u, web_tp_set in utw_seq.items():
                        if t in web_tp_set:
                            n += 1
                    if n > uu:
                        uu = n
                        pattern = t
        return list(pattern)
