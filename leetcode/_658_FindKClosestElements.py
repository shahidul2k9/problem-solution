from typing import List


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr.sort(key=lambda a: [abs(a - x), a])

        while len(arr) > k:
            arr.pop()
        arr.sort()
        return arr
