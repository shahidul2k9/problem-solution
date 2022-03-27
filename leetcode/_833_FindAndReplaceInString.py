from typing import List


class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        seq = []
        rm = {v: (sources[i], targets[i]) for i, v in enumerate(indices)}
        i = 0
        while i < len(s):
            if i in rm:
                if s.startswith(rm[i][0], i):
                    seq.append(rm[i][1])
                    i += len(rm[i][0])
                else:
                    seq.append(s[i])
                    i += 1
            else:
                seq.append(s[i])
                i += 1
        return ''.join(seq)
