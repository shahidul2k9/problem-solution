import collections
from typing import List


class MagicDictionary:

    def __init__(self):
        self.len_to_words = collections.defaultdict(list)

    def buildDict(self, dictionary: List[str]) -> None:
        for w in dictionary:
            self.len_to_words[len(w)].append(w)

    def search(self, searchWord: str) -> bool:
        for w in self.len_to_words[len(searchWord)]:
            diff = 0
            for i in range(len(w)):
                if w[i] != searchWord[i]:
                    diff += 1
                if diff > 1:
                    break
            else:
                if diff == 1:
                    return True
        return False

# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)