from typing import List


class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        arr = [0] * length
        for a, b, val in updates:
            arr[a] += val
            if b + 1 < length:
                arr[b + 1] -= val
        s = 0
        for i in range(length):
            s += arr[i]
            arr[i] = s
        return arr
