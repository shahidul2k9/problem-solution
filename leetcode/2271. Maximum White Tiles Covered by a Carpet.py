from typing import List


class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort()
        prefix_sum = []
        for [l, r] in tiles:
            if len(prefix_sum) == 0:
                prefix_sum.append(r - l + 1)
            else:
                prefix_sum.append(prefix_sum[-1] + r - l + 1)
        max_coverage = 0
        j = 0
        for i, (li, ri) in enumerate(tiles):
            while j + 1 < len(tiles) and li + carpetLen >= tiles[j + 1][0]:
                j += 1
            lj, rj = tiles[j]

            diff = prefix_sum[j] - (prefix_sum[i - 1] if i - 1 >= 0 else 0)
            if li + carpetLen - 1 < rj:
                diff = diff - (rj - (li + carpetLen - 1))
            max_coverage = max(max_coverage, diff)
        return max_coverage


