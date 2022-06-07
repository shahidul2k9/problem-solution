from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        low = 0
        high = n
        while low + 1 < high:
            cn = high - low
            half = cn // 2
            if half % 2 == 1:
                half += 1
            # print(low, high, cn, half)
            if nums[low + half - 2] == nums[low + half - 1]:
                low = low + half
            else:
                high = low + half - 1
        return nums[low]
