from typing import List


class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        opt_dist = 0
        for i, v in enumerate(nums2):
            low = 0
            high = min(i, len(nums1) - 1)
            while low <= high:
                mid = (low + high) // 2
                if nums1[mid] > v:
                    low = mid + 1
                else:
                    high = mid - 1
            if low <= min(i, len(nums1) - 1) and nums1[low] <= v:
                opt_dist = max(opt_dist, i - low)
        return opt_dist


