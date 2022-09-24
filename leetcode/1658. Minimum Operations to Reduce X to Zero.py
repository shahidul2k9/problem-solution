from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        if sum(nums) < x:
            return -1
        min_count = float('inf')
        prefix = [0]
        for val in nums:
            prefix.append(prefix[-1] + val)
        left = 0
        right = 1
        while left < len(prefix) and right < len(prefix) + 1:
            s = prefix[left] + prefix[-1] - prefix[right-1]
            if s <= x:
                if s == x:
                    min_count = min(min_count, left + len(prefix) - right)
                left += 1
            else:
                right += 1
        if min_count < float('inf'):
            return min_count
        else:
            return -1