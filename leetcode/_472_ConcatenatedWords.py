from typing import List


class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:

        def addWord(w):
            x = root
            for c in w:
                if c not in x:
                    x[c] = {}
                x = x[c]
            x['$'] = True

        def isWord(w, from_index, must_split=False):
            n = root
            for i in range(from_index, len(w)):
                c = w[i]
                if '$' in n and i > from_index and isWord(w, i, False):
                    return True
                if c not in n:
                    return False
                n = n[c]
            if must_split:
                return False
            else:
                return '$' in n

        root = {}
        for w in words:
            addWord(w)
        concatenated_words = []

        for w in words:
            if isWord(w, 0, True):
                concatenated_words.append(w)
        return concatenated_words
