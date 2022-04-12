# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        ps = collections.defaultdict(int)
        ans = 0

        def preorder(cr, s):
            nonlocal ans
            if cr:
                s += cr.val
                if s == targetSum:
                    ans += 1
                ans += ps[s - targetSum]
                ps[s] += 1

                preorder(cr.left, s)
                preorder(cr.right, s)
                ps[s] -= 1

        preorder(root, 0)
        return ans


