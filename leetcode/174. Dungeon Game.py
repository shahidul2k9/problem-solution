from functools import lru_cache
from typing import List

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])

        @lru_cache(None)
        def find_min_health(r: int, c: int) -> int:
            if r == m - 1 and c == n - 1:
                return max(1, 1 - dungeon[r][c])
            else:
                min_deficit = float('inf')
                for [dr, dc] in [[1, 0], [0, 1]]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n:
                        min_deficit = min(min_deficit, find_min_health(nr, nc))
                return max(1, min_deficit - dungeon[r][c])

        return find_min_health(0, 0)

