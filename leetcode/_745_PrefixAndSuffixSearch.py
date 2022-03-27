from typing import List


class WordFilter:

    def __init__(self, words: List[str]):
        self.trie = {}
        self.words = words

        def add_word(w, index):
            tn = self.trie
            tn['*'] = index
            for c in w:
                if c not in tn:
                    tn[c] = {}
                tn = tn[c]
                tn['*'] = index

        for i, w in enumerate(words):
            suffix = w + '#' + w
            for k in range(len(suffix)):
                if suffix[k] == '#':
                    break
                else:
                    add_word(suffix[k:], i)

    def f(self, prefix: str, suffix: str) -> int:
        word = suffix + '#' + prefix
        tn = self.trie
        for c in word:
            if c in tn:
                tn = tn[c]
            else:
                return -1
        return tn['*']
