from typing import List


class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        lo = 0
        hi = len(nums) - 1
        last_known = len(nums) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            n = nums[mid] - nums[0] + 1
            missing_n = n - (mid + 1)
            if missing_n >= k:
                last_known = mid - 1
                hi = mid - 1
            else:
                lo = mid + 1
        # print(last_known)
        missing_nums = (nums[last_known] - nums[0] + 1) - (last_known + 1)
        return nums[last_known] + k - missing_nums
