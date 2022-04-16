# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
        ss = []
        def dfs(sb):
            if not sb:
                return 0
            else:
                s = dfs(sb.left) + dfs(sb.right) + sb.val
                ss.append(s)
                return s
        dfs(root)
        total = ss.pop()
        return total % 2 == 0 and (total//2) in ss
