# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional


class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(sb, par_val) -> int:
            nonlocal ans
            if not sb:
                return [True, par_val]
            else:
                left_uni, left_val = dfs(sb.left, sb.val)
                right_uni, right_val = dfs(sb.right, sb.val)
                if left_uni and right_uni and left_val == sb.val and right_val == sb.val:
                    ans += 1
                    return [True, sb.val]
                else:
                    return [False, None]
        if root:
            dfs(root, root.val)
        return ans