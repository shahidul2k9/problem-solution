import collections
from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:

        bit_len = len(bin(max(nums) - 2))
        n = len(nums)
        fc = collections.defaultdict(int)
        for v in nums:
            for i in range(bit_len):
                if (1 << i) & v:
                    fc[i] += 1
        total_hamming_distance = 0
        for v in nums:
            for i in range(bit_len):
                if (1 << i) & v:
                    xn = n - fc[i]
                else:
                    xn = fc[i]
                total_hamming_distance += xn
        return total_hamming_distance // 2



