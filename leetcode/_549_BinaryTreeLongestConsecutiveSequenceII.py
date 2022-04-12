# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(r):
            nonlocal ans
            if not r:
                return [0, 0, float('inf')]
            val = r.val
            left = dfs(r.left)
            right = dfs(r.right)
            t = [1, 1, r.val]
            if abs(t[2]-left[2]) == 1:
                if t[2] - left[2] > 0:
                    t[1] = max(t[1], left[1] + 1)
                else:
                    t[0] = max(t[0], 1 + left[0])
            if abs(t[2] - right[2]) == 1:
                if t[2] - right[2] > 0:
                    t[1] = max(t[1], right[1] + 1)
                else:
                    t[0] = max(t[0], 1 + right[0])
            ans = max(t[0] + t[1] - 1, ans)
            return t
        dfs(root)
        return ans