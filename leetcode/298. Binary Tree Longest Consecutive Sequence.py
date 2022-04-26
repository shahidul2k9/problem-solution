# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        ans = 1

        def btlscs(sb):
            nonlocal ans
            lsc = 1
            if sb.left or sb.right:
                if sb.left:
                    left = btlscs(sb.left)
                    diff = sb.val - sb.left.val
                    if diff == -1:
                        lsc = 1 + left
                if sb.right:
                    right = btlscs(sb.right)
                    diff = sb.val - sb.right.val
                    if diff == -1:
                        lsc = max(lsc, 1 + right)
            ans = max(ans, lsc)
            return lsc

        btlscs(root)
        return ans




