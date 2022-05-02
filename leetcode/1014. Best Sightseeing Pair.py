from typing import List


class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        dragged_values = values[:]
        for i in range(n - 2, -1, -1):
            dragged_values[i] = max(dragged_values[i + 1] - 1, dragged_values[i])
        ans = 0
        for i in range(n - 1):
            ans = max(ans, values[i] + dragged_values[i + 1] - 1)
        return ans
