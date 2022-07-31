from typing import List


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] += prefix_sum[i - 1] + nums[i - 1]
        average = [-1] * n
        for i in range(k + 1, n + 1 - k):
            average[i - 1] = (prefix_sum[i + k] - prefix_sum[i - k - 1]) // (2 * k + 1)
        return average
