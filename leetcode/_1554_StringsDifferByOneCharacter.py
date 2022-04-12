from typing import List


class Solution:
    def differByOne(self, dict: List[str]) -> bool:

        for i in range(len(dict[0])):
            word_set = set()
            for w in dict:
                mw = w[:i] + '*' + w[i + 1:]
                if mw in word_set:
                    return True
                else:
                    word_set.add(mw)
        return False
