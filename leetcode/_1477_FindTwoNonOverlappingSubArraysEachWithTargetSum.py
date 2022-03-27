from typing import List


class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        prefix_sum = {0: -1}
        so_far_min = {-1: float('inf')}
        sum = 0
        ans = float('inf')
        for i, v in enumerate(arr):
            sum += v
            prefix_sum[sum] = i
            cp = sum - target

            if cp in prefix_sum:
                cp_index = prefix_sum[cp]
                so_far_min[i] = min(so_far_min[i - 1], i - cp_index)
                ans = min(ans, (i - cp_index) + so_far_min[cp_index])
            else:
                so_far_min[i] = so_far_min[i - 1]

        if ans < float('inf'):
            return ans
        else:
            return -1
