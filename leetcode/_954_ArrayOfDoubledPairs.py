import collections
from typing import List


class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        fc = collections.Counter(arr)
        arr.sort(key= lambda x : abs(x))
        for v in arr:
            if fc[v] > 0:
                if fc.get(2 * v, 0) < 1:
                    return False
                else:
                    fc[v] -= 1
                    fc[2 * v] -= 1
        return True
