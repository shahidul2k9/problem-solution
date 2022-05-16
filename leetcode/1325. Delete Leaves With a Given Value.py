class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional


class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        def delete_leaves(sb) -> bool:
            if sb:
                left_del = delete_leaves(sb.left)
                right_del = delete_leaves(sb.right)
                if sb.val == target and left_del and right_del:
                    return True
                if left_del:
                    sb.left = None
                if right_del:
                    sb.right = None
                return False
            return True
        return None if delete_leaves(root) else root