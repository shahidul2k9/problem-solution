from typing import List


class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        ps = {0: -1}
        s = 0
        ans = 0
        for i, v in enumerate(nums):
            s += v
            if s - k in ps:
                ans = max(ans, i - ps[s - k])
            if s not in ps:
                ps[s] = i
        return ans
