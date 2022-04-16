# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def find_max_index(x, y):
            idx = x
            for i in range(x + 1, y + 1):
                if nums[i] > nums[idx]:
                    idx = i
            return idx

        def build(a, b):
            if a > b:
                return None
            else:
                max_idx = find_max_index(a, b)
                root = TreeNode(nums[max_idx])
                root.left = build(a, max_idx - 1)
                root.right = build(max_idx + 1, b)
                return root

        return build(0, len(nums) - 1)
