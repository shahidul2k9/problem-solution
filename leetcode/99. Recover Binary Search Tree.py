# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        stack = []
        nd = root
        prev = x = y = None
        swapee = []
        while nd or stack:
            while nd:
                stack.append(nd)
                nd = nd.left
            nd = stack.pop()
            if prev and prev.val > nd.val:
                if x is None:
                    x = prev
                y = nd
            prev = nd
            nd = nd.right
        x.val, y.val = y.val, x.val


