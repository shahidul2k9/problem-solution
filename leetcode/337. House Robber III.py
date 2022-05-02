from functools import lru_cache
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional


class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        @lru_cache(maxsize = None)
        def collect_max(sb, collectible)-> int:
            if sb:
                collection = 0
                if collectible:
                    collection = collect_max(sb.left, False) + collect_max(sb.right, False) + sb.val
                return max(collection, collect_max(sb.left, True) + collect_max(sb.right, True))
            return 0
        return max(collect_max(root, True), collect_max(root, False))