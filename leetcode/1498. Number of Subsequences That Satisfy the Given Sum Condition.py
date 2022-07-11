from bisect import bisect
from typing import List


class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        n = len(nums)
        p2 = [1]
        while len(p2) < n:
            p2.append((p2[-1] * 2) % 1_000_000_007)
        nums.sort()
        low = 0
        ans = 0
        while low < n and 2 * nums[low] <= target:
            high = bisect.bisect_right(nums, target - nums[low], lo = low, hi = n)
            seq_len = high - low
            ans = (ans + p2[seq_len - 1]) % 1_000_000_007
            low += 1
        return ans