# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(r):
            if not r:
                return 0, None
            ld, ln = dfs(r.left)
            rd, rn = dfs(r.right)
            if ld > rd:
                return 1 + ld, ln
            elif rd > ld:
                return 1 + rd, rn
            else:
                return 1 + ld, r

        return dfs(root)[1]
