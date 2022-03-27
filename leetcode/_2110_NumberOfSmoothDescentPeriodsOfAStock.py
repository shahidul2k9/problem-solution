from typing import List


class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        previous_price = float('-inf')
        steak = 0
        sdp = 0
        for p in prices:
            if previous_price == p + 1:
                steak += 1
            else:
                steak = 1
            sdp += steak
            previous_price = p
        return sdp
