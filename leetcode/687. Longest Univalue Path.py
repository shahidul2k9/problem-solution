# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional


class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def dfs(sb):
            nonlocal ans
            if not sb:
                return 0
            else:
                left_n = dfs(sb.left)
                right_n = dfs(sb.right)
                sb_n = 1
                n = 0
                if left_n > 0 and sb.val == sb.left.val:
                    sb_n = 1 + left_n
                    n = left_n
                if right_n > 0 and sb.val == sb.right.val:
                    sb_n = max(sb_n, right_n + 1)
                    n += right_n
                ans = max(ans, n)
                return sb_n

        dfs(root)
        return ans