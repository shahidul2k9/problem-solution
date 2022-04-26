from typing import List


class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def min_swap_to_make_top_eq(face):
            sw = 0
            for i in range(len(tops)):
                if tops[i] != face:
                    if bottoms[i] == face:
                        sw += 1
                    else:
                        return float('inf')
            return sw

        ans = float('inf')
        for f in range(1, 7):
            ans = min(ans, min_swap_to_make_top_eq(f))
        tops, bottoms = bottoms, tops
        for f in range(1, 7):
            ans = min(ans, min_swap_to_make_top_eq(f))

        return ans if ans != float('inf') else -1

