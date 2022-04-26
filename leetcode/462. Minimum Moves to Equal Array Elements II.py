from typing import List


class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        avg = nums[len(nums) // 2]
        moves = 0
        for v in nums:
            moves += abs(v - avg)
        return moves
