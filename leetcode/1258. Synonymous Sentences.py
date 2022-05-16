import collections
from typing import List


class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        g = collections.defaultdict(set)
        for u, v in synonyms:
            g[u].add(v)
            g[v].add(u)

        def dfs(u, cc):
            if u not in cc:
                cc.add(u)
                for v in g[u]:
                    dfs(v, cc)

        original_sentence = text.split()
        sentence_list = []

        def bracktrack(seq):
            if len(seq) == len(original_sentence):
                sentence_list.append(' '.join(seq))
            else:
                word = original_sentence[len(seq)]
                choices = set()
                if word in g:
                    dfs(word, choices)
                else:
                    choices.add(word)
                for w in sorted(choices):
                    seq.append(w)
                    bracktrack(seq)
                    seq.pop()

        bracktrack([])
        return sentence_list


