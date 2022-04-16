# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:

        ans = 0

        def zigzag(nd):
            nonlocal ans
            if nd:
                left = zigzag(nd.left)
                right = zigzag(nd.right)
                zz = [left[1] + 1, right[0] + 1]
                ans = max(ans, max(zz))
                return zz
            else:
                return -1, -1

        zigzag(root)
        return ans