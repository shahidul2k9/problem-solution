from typing import List


class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        anomaly_count = 0
        max_val = nums[0]
        for i in range(len(nums) - 1):
            if nums[i + 1] < nums[i]:
                anomaly_count += 1
                if i == 0 or nums[i - 1] <= nums[i + 1]:
                    nums[i] = nums[i + 1]
                else:
                    nums[i + 1] = nums[i]
            if anomaly_count > 1:
                return False
        return True
