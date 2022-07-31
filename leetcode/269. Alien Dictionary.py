import collections
from typing import List


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        g = collections.defaultdict(set)
        in_degree = {ch: 0 for w in words for ch in w}

        for w1, w2 in zip(words, words[1:]):
            k = 0
            min_len = min(len(w1), len(w2))
            while k < min_len and w1[k] == w2[k]:
                k += 1
            if k < min_len:
                u = w1[k]
                v = w2[k]
                if v not in g[u]:
                    g[u].add(v)
                    in_degree[v] += 1
            else:
                if len(w1) > len(w2):
                    return ''

        alphabet = []
        q = collections.deque([])
        for key, value in in_degree.items():
            if value == 0:
                q.append(key)
        while q:
            u = q.popleft()
            alphabet.append(u)
            for v in g[u]:
                in_degree[v] -= 1
                if in_degree[v] == 0:
                    q.append(v)

        if len(alphabet) < len(in_degree):
            return ''
        else:
            return ''.join(alphabet)

