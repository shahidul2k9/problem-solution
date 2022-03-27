from typing import List


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        cpn = len(cardPoints)
        ps = [0] * (cpn + 1)
        for i in range(1, len(ps)):
            ps[i] = ps[i - 1] + cardPoints[i - 1]

        mx = float('-inf')
        for i in range(k + 1):
            mx = max(mx, ps[i] + ps[cpn] - ps[cpn - (k - i)])
        return mx
