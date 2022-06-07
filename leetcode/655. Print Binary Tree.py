# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional


class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        h = 0

        def calculate_dimention(sb, r, c):
            nonlocal h
            if sb:
                h = max(h, r)
                calculate_dimention(sb.left, r + 1, c - 1)
                calculate_dimention(sb.right, r + 1, c + 1)

        calculate_dimention(root, 0, 0)

        n = 2 ** (h + 1) - 1
        mat = [[""] * n for _ in range(h + 1)]

        def pre_order(sb, r, c):
            if sb:
                mat[r][c] = str(sb.val)

                pre_order(sb.left, r + 1, c - (2 ** (h - r - 1)))
                pre_order(sb.right, r + 1, c + (2 ** (h - r - 1)))

        pre_order(root, 0, (n - 1) // 2)
        return mat

