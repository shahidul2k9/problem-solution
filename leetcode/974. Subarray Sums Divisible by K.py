from collections import Counter
from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        frequency = Counter()
        prefix_sum = 0
        count = 0
        for v in nums:
            prefix_sum += v
            if prefix_sum % k == 0:
                count += 1
            prefix_sum %= k

            count += frequency[prefix_sum]

            frequency[prefix_sum] += 1
        return count
