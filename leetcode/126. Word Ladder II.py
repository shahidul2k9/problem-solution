import collections
from typing import List


class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        word_to_index = {word: index for index, word in enumerate(wordList)}
        if endWord not in word_to_index:
            return []
        n = len(wordList)
        if beginWord not in word_to_index:
            word_to_index[beginWord] = n
            n += 1
        index_to_word = {index: word for word, index in word_to_index.items()}
        g = collections.defaultdict(set)
        for word1, u in word_to_index.items():
            for word2, v in word_to_index.items():
                diff = 0
                for ch1, ch2 in zip(word1, word2):
                    if ch1 != ch2:
                        diff += 1
                if diff == 1:
                    g[u].add(v)
                    g[v].add(u)
        parent = [set() for _ in range(n)]
        start_index = word_to_index[beginWord]
        end_index = word_to_index[endWord]
        q = collections.deque([start_index])
        d = [float('inf')] * n
        d[start_index] = 0
        while q:
            u = q.popleft()
            for v in g[u]:
                if d[v] > d[u] + 1:
                    d[v] = d[u] + 1
                    q.append(v)
                    parent[v].add(u)
                elif d[v] == d[u] + 1:
                    parent[v].add(u)
        shortest_paths = []

        def bracktrack(v, path):
            if v == start_index:
                shortest_paths.append(path[::-1])
            else:
                for u in parent[v]:
                    path.append(index_to_word[u])
                    bracktrack(u, path)
                    path.pop()

        bracktrack(end_index, [endWord])
        return shortest_paths

