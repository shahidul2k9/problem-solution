from typing import List


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        def count_seq(l, r) -> int:
            n = r - l + 1
            n -= 2  # remove(n-1 and n) 1 + 2 + 3 + ...+ n-1 + n
            if n >= 0:
                return (n * (n + 1)) // 2
            else:
                return 0

        left = 0
        right = 1
        ans = 0
        while right + 1 < len(nums):
            if nums[right + 1] - nums[right] != nums[right] - nums[right - 1]:
                sba = count_seq(left, right)
                ans = ans + sba
                left = right
                right = left + 1
            else:
                right += 1
        ans += count_seq(left, right)
        return ans



