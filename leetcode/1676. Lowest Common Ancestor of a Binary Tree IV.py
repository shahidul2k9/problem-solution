# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        node_set = set(nodes)
        trace_count = collections.defaultdict(int)
        lca = None
        def dfs(sb) -> int:
            nonlocal lca
            if not sb:
                return 0
            else:
                left = dfs(sb.left)
                right = dfs(sb.right)
                count = left + right + (1 if sb in node_set else 0)
                if count == len(node_set) and lca is None:
                    lca = sb
                return count
        dfs(root)
        return lca