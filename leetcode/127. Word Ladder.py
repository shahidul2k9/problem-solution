import collections


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        start = -1
        end = -1
        for i, word in enumerate(wordList):
            if beginWord == word:
                start = i
            if endWord == word:
                end = i
        if start == -1:
            wordList.append(beginWord)
            start = len(wordList) - 1
        n = len(wordList)
        g = collections.defaultdict(set)
        ##########TLE##################
        #for u in range(n):
        #     for v in range(u + 1, n):
        #         w1 = wordList[u]
        #         w2 = wordList[v]
        #         if len(w1) == len(w2):
        #             diff = 0
        #             for idx in range(len(w1)):
        #                 if w1[idx] != w2[idx]:
        #                     diff += 1
        #             if diff == 1:
        #                 g[u].add(v)
        #                 g[v].add(u)

        alphabet = [chr(asci) for asci in range(ord('a'), ord('z') + 1)]
        word_idx = {w: i for i, w in enumerate(wordList)}
        for u, w in enumerate(wordList):
            for pos in range(len(w)):
                for rc in alphabet:
                    if w[pos] != rc:
                        w2 = w[:pos] + rc + w[pos + 1:]
                        v = word_idx.get(w2, -1)
                        if v != -1:
                            g[u].add(v)
                            g[v].add(u)

        def bfs(source, destination) -> int:
            colored = set()
            q = collections.deque([[source, 0]])
            colored.add(source)
            while q:
                u, d = q.popleft()
                if u == destination:
                    return d + 1
                else:
                    for v in g[u]:
                        if v not in colored:
                            colored.add(v)
                            q.append([v, d + 1])
            return 0

        return bfs(start, end)
