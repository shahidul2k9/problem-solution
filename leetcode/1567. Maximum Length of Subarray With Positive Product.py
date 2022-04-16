from typing import List


class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] < 0:
                nums[i] = -1
            elif nums[i] > 0:
                nums[i] = 1
            else:
                nums[i] = 0
        p = 1
        neg_index = None
        ans = left = 0
        for i, v in enumerate(nums):
            if v < 0 and neg_index == None:
                neg_index = i
            if v != 0:
                p *= v
                if p > 0:
                    ans = max(ans, i - left + 1)
                else:
                    ans = max(ans, i - neg_index)
            else:
                p = 1
                neg_index = None
                left = i + 1
        return ans
