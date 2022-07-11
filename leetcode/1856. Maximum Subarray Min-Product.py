from typing import List


class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stack = []
        prefix = [0]
        for i in range(n):
            while stack and nums[stack[-1]] >= nums[i]:
                right[stack.pop()] = i
            if stack:
                left[i] = stack[-1]
            stack.append(i)
            prefix.append(prefix[-1] + nums[i])

        ans = 0
        for i in range(n):
            ans = max(ans, nums[i] * (prefix[right[i]] - prefix[left[i] + 1]))
        return ans % (10 ** 9 + 7)


