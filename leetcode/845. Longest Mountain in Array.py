from typing import List
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        ans = start = end = 0
        n = len(arr)
        while start < n:
            end = start
            if end + 1 < n and arr[end] < arr[end + 1]:
                while end + 1 < n and arr[end] < arr[end + 1]:
                    end += 1
                if end + 1 < n and arr[end] > arr[end + 1]:
                    while end + 1 < n and arr[end] > arr[end + 1]:
                        end += 1
                    ans = max(ans, end - start + 1)
            start = max(start + 1, end)
        return ans