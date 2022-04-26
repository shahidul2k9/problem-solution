# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def is_bst(sr):
            nonlocal ans
            val = sr.val
            ret = None
            if not sr.left and not sr.right:
                ret = [True, val, val, 1]
            elif not sr.left:
                right = is_bst(sr.right)
                if right[0] and val < right[1]:
                    ret = [True, val, right[2], 1 + right[3]]
            elif not sr.right:
                left = is_bst(sr.left)
                if left[0] and left[2] < val:
                    ret = [True, left[1], val, 1 + left[3]]
            else:
                left = is_bst(sr.left)
                right = is_bst(sr.right)
                if left[0] and right[0] and left[2] < val < right[1]:
                    ret = [True, left[1], right[2], 1 + left[3] + right[3]]
            if ret:
                ans = max(ans, ret[3])
            else:
                ret = [False, 0, 0, 0]
            return ret

        if root:
            is_bst(root)
        return ans

