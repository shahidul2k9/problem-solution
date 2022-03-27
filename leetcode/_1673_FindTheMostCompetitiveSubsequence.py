from typing import List


class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stack = []
        n = len(nums)
        for i, v in enumerate(nums):
            while stack and stack[-1] > v and len(stack) + (n - i) > k:
                stack.pop()
            if len(stack) < k:
                stack.append(v)
        return stack
