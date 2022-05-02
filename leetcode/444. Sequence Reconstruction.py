import collections
from typing import List


class Solution:
    def sequenceReconstruction(self, nums: List[int], sequences: List[List[int]]) -> bool:
        n = len(nums)
        ind = [0] * (n + 1)
        q = collections.deque()
        g = collections.defaultdict(list)
        for seq in sequences:
            for u, v in zip(seq, seq[1:]):
                ind[v] += 1
                g[u].append(v)
        for u in range(1, n + 1):
            if ind[u] == 0:
                q.append(u)
        while len(q) == 1:
            u = q.popleft()
            for v in g[u]:
                ind[v] -= 1
                if ind[v] == 0:
                    q.append(v)
        return len(q) == 0

