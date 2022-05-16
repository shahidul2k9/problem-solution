from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        mp = [[0] * len(triangle[r]) for r in range(len(triangle))]

        mp[0][:] = triangle[0][:]
        for r in range(1, len(triangle)):
            for c in range(len(triangle[r])):
                mp[r][c] = min(mp[r - 1][c] if c < len(triangle[r - 1]) else float('inf'),
                               mp[r - 1][c - 1] if c > 0 else float('inf')) + triangle[r][c]
        return min(mp[-1])