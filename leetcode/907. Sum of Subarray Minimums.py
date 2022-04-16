from typing import List


class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        mod = 10 ** 9 + 7
        stack = []
        ans = 0
        for i, v in enumerate(arr):
            left = i
            while stack and stack[-1][2] >= v:
                left, org_pos, left_val = stack.pop()
                ans += (org_pos - left + 1) * (i - org_pos) * left_val
                ans %= mod
            stack.append([left, i, v])
        while stack:
            left, org_pos, v = stack.pop()
            ans += (org_pos - left + 1) * (len(arr) - org_pos) * v
            ans %= mod
        return ans
