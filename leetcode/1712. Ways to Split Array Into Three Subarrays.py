from bisect import bisect
from typing import List


class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        prefix = [nums[0]]
        n = len(nums)
        for index in range(1, n):
            prefix.append(prefix[-1] + nums[index])
        splits = 0
        for index in range(n-2):
            mid_low = bisect.bisect_left(prefix, 2* prefix[index], index+1, n-1 )
            if mid_low < n - 1 and (prefix[mid_low] - prefix[index] <= prefix[n-1] - prefix[mid_low]):
                low = mid_high = mid_low
                high = n - 2
                while low <= high:
                    mid = (low + high)//2
                    if prefix[mid] - prefix[index] <= prefix[n-1] - prefix[mid]:
                        mid_high = mid
                        low = mid + 1
                    else:
                        high = mid - 1
                splits = (splits + mid_high - mid_low + 1) % 1_000_000_007
        return splits