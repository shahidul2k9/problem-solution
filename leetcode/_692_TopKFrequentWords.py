import functools


class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[str]:
        word_frequency = {}
        for w in words:
            word_frequency[w] = word_frequency.get(w, 0) + 1
        frequency_tuple = list(word_frequency.items())
        frequency_tuple.sort(key=functools.cmp_to_key(self.word_cmp))
        ans = []
        print(frequency_tuple)
        for i in range(k):
            ans.append(frequency_tuple[i][0])
        return ans


    def word_cmp(self, x, y):
        if x[1] != y[1]:
            return -(x[1] - y[1])
        elif x[0] < y[0]:
            return -1
        elif x[0] > y[0]:
            return 1
        else:
            return 0
