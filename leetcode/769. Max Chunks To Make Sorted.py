from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        left = i = 0
        right = arr[i]
        chunks = 0
        while i < len(arr):
            if i == right:
                chunks += 1
                left = right + 1

            i += 1
            if i < len(arr):
                right = max(right, arr[i])
        return chunks
