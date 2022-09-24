from typing import List


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:

        def find_peak(left: int, right: int) -> int:
            mid = (left + right) // 2
            if mid - 1 >= 0 and mid + 1 < len(arr):
                if arr[mid - 1] < arr[mid] < arr[mid + 1]:
                    return find_peak(mid, right)
                elif arr[mid - 1] > arr[mid] > arr[mid + 1]:
                    return find_peak(left, mid)
            return mid

        return find_peak(0, len(arr) - 1)