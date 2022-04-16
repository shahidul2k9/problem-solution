from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        fi = dict()
        fi[0] = -1
        n = 0
        ans = 0
        for i, b in enumerate(nums):
            if b == 0:
                n -= 1
            else:
                n += 1
            if n in fi:
                ans = max(ans, i - fi[n])
            else:
                fi[n] = i
        return ans
