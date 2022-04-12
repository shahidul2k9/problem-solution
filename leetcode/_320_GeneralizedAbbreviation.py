from typing import List


class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        def backtrack(seq: List[str], pos: int, abb_prefix: bool, abb_list):
            if pos >= len(word):
                abb_list.append(''.join(seq))

            for i in range(pos, len(word)):
                if abb_prefix:
                    v = str(i - pos + 1)
                else:
                    v = word[pos:i + 1]
                seq.append(v)
                backtrack(seq, i + 1, not abb_prefix, abb_list)
                seq.pop()

        ans = []
        backtrack([], 0, True, ans)
        backtrack([], 0, False, ans)
        return ans

