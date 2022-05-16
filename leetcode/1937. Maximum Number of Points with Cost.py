from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m, n = len(points), len(points[0])
        bucket = [0] * n
        left_sweep = [0] * (n + 1)
        for r in range(m):
            for c in range(n - 1, -1, -1):
                left_sweep[c] = max(left_sweep[c + 1] - 1, bucket[c])
            right_sweep = 0
            for c in range(0, n):
                right_sweep = max(bucket[c], right_sweep - 1)
                bucket[c] = max(right_sweep, left_sweep[c])

            for c in range(n):
                bucket[c] += points[r][c]

        return max(bucket)

