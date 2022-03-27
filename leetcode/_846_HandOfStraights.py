from collections import Counter
from typing import List


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        s = Counter(hand)
        for v in hand:
            if s[v] > 0:
                ck = 0
                while ck < groupSize and s[v + ck] > 0:
                    s[v + ck] -= 1
                    ck += 1
                if ck < groupSize:
                    return False
        return True
