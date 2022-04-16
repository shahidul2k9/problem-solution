from typing import List


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        gt = [-1] * n

        stack = []
        for i, v in enumerate(nums + nums):
            while stack and stack[-1][1] < v:
                pos, _ = stack.pop()
                gt[pos] = v
            if i < n:
                stack.append([i, v])

        return gt
