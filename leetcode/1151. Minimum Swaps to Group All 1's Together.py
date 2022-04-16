from typing import List


class Solution:
    def minSwaps(self, data: List[int]) -> int:
        w = sum(data)
        left = right = 0
        s = 0
        max_ones = 0
        while right < len(data):
            s += data[right]
            right += 1
            if right - left == w:
                max_ones = max(max_ones, s)
                s -= data[left]
                left += 1
        return w - max_ones


