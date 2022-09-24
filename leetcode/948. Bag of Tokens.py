from typing import List


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        lo = 0
        hi = len(tokens) - 1
        scores = 0
        while lo <= hi:
            if tokens[lo] <= power:
                power -= tokens[lo]
                scores += 1
                lo += 1
            elif lo < hi and tokens[lo] <= power + tokens[hi] and scores > 0:
                power += tokens[hi]
                hi -= 1
                scores -= 1
            else:
                break
        return scores