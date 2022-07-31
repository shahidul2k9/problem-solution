class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional


class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        def find_lca(sub_root : TreeNode)-> TreeNode:
            if not sub_root:
                return None
            else:
                if sub_root.val == p or sub_root.val == q:
                    return sub_root
                left_lca = find_lca(sub_root.left)
                right_lca = find_lca(sub_root.right)
                if left_lca != None and right_lca != None:
                    return sub_root
                if left_lca == None:
                    return right_lca
                else:
                    return left_lca
        total_dist = 0
        def dfs(sub_root, dist):
            nonlocal total_dist
            if sub_root:
                if sub_root.val == p or sub_root.val == q:
                    total_dist += dist
                dfs(sub_root.left, dist + 1)
                dfs(sub_root.right, dist + 1)
            return total_dist
        lca = find_lca(root)
        dfs(lca, 0)
        return total_dist