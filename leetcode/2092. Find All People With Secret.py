import collections
from typing import List


class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        secret_group = {0, firstPerson}
        gt = {}
        for u, v, t in meetings:
            if t not in gt:
                gt[t] = collections.defaultdict(set)
            g = gt[t]
            g[u].add(v)
            g[v].add(u)

        for t in sorted(gt.keys()):
            g = gt[t]
            q = collections.deque()
            for u in g.keys():
                if u in secret_group:
                    q.append(u)
            while q:
                u = q.popleft()
                for v in g[u]:
                    if v not in secret_group:
                        q.append(v)
                        secret_group.add(v)
        return list(secret_group)