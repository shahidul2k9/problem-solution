from typing import List


class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        R = len(nums)
        C = max([len(c) for c in nums])
        diagonal_matrix = [[] for _ in range(R + C - 1)]
        for r in range(R):
            for c in range(len(nums[r])):
                diagonal_matrix[r + c].append((r, nums[r][c]))

        while len(diagonal_matrix[-1]) == 0:
            diagonal_matrix.pop()

        for r in range(len(diagonal_matrix)):
            diagonal_matrix[r].sort(key=lambda x: -x[0])
        diagonal_thread = []
        for r in range(len(diagonal_matrix)):
            for c in range(len(diagonal_matrix[r])):
                diagonal_thread.append(diagonal_matrix[r][c][1])
        return diagonal_thread
