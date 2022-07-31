from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        chunks = 0
        index = 0
        max_val = 0
        n = len(arr)
        while index < n:
            max_val = arr[index]
            right = n - 1
            while right > index:
                if arr[right] < max_val:
                    while index < right:
                        index += 1
                        max_val = max(max_val, arr[index])
                    right = n - 1
                else:
                    right -= 1

            else:
                chunks += 1
            index += 1
        return chunks
