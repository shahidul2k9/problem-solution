from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        def trim(sb):
            if not sb:
                return None
            if sb.val < low:
                return trim(sb.right)
            if sb.val > high:
                return trim(sb.left)
            sb.left = trim(sb.left)
            sb.right = trim(sb.right)
            return sb

        return trim(root)
