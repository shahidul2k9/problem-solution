from collections import Counter
from typing import List


class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        def permutate(seq, pos, collector):
            if pos == len(seq):
                collector.add(''.join(seq))
            for i in range(pos, len(seq)):
                seq[pos], seq[i] = seq[i], seq[pos]
                permutate(seq, pos + 1, collector)
                seq[pos], seq[i] = seq[i], seq[pos]

        fc = Counter(s)
        odd_char = ''
        unique_odd_char_count = 0
        char_seq = []
        for c, f in fc.items():
            if f % 2 == 1:
                odd_char = c
                unique_odd_char_count += 1
            h = f // 2
            if h > 0:
                char_seq.extend(c * h)
        if unique_odd_char_count > 1:
            return []
        else:
            if len(s) == 1:
                return [s]
            else:
                half_permuation = set()
                permutate(char_seq, 0, half_permuation)
                full_permuation = []
                for hp in half_permuation:
                    full_permuation.append(hp + odd_char + hp[::-1])
                return full_permuation

