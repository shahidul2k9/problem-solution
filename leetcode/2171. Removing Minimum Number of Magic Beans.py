from typing import List


class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        n = len(beans)
        beans.sort()
        prefix_total = min_operations = sum(beans)
        suffix_total = 0
        for index in range(n - 1, -1, -1):
            val = beans[index]
            prefix_total -= val
            suffix_total += val
            min_operations = min(suffix_total - (n - index) * val + prefix_total, min_operations)
        return min_operations

