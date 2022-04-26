import collections
from typing import List


class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        shift_group = collections.defaultdict(list)
        for w in strings:
            shift = ord(w[0]) - ord('a')
            shifted_word = []
            for ch in w:
                idx = ord(ch) - shift
                if idx < 97:
                    idx += 26
                shifted_word.append(chr(idx))

            sw = ''.join(shifted_word)
            shift_group[sw].append(w)
        return shift_group.values()

