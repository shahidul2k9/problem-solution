# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def inorder(sb, arr):
            if sb:
                inorder(sb.left, arr)
                arr.append(sb.val)
                inorder(sb.right, arr)

        arr1 = []
        arr2 = []
        inorder(root1, arr1)
        inorder(root2, arr2)
        left1 = 0
        right2 = len(arr2) - 1
        while left1 < len(arr1) and right2 >= 0:
            s = arr1[left1] + arr2[right2]
            if s == target:
                return True
            elif s < target:
                left1 += 1
            else:
                right2 -= 1
        return False
