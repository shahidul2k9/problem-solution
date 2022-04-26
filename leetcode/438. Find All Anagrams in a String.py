from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pf = [0] * 26
        sf = [0] * 26
        for ch in p:
            idx = ord(ch) - ord('a')
            pf[idx] += 1
        anagram_positions = []
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            sf[idx] += 1
            if i + 1 >= len(p):
                for k in range(26):
                    if pf[k] != sf[k]:
                        break
                else:
                    anagram_positions.append(i - len(p) + 1)
                ex_idx = ord(s[i - len(p) + 1]) - ord('a')
                sf[ex_idx] -= 1
        return anagram_positions

