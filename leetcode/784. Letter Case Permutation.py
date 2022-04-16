from typing import List


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        permutation_list = []

        def permutate(seq):
            if len(seq) == len(s):
                permutation_list.append(''.join(seq))
            else:
                pos = len(seq)
                ch = s[pos]
                if not ch.isdigit():
                    com_ch = ch.lower() if ch.isupper() else ch.upper()
                    seq.append(com_ch)
                    permutate(seq)
                    seq.pop()
                seq.append(ch)
                permutate(seq)
                seq.pop()

        permutate([])
        return permutation_list
