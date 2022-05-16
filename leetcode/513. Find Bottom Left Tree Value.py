from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        ans = [None, -1]

        def pre_order_dfs(sb, depth):
            nonlocal ans
            if sb:
                if ans[1] < depth:
                    ans = [sb, depth]
                pre_order_dfs(sb.left, depth + 1)
                pre_order_dfs(sb.right, depth + 1)

        pre_order_dfs(root, 0)
        return ans[0].val
