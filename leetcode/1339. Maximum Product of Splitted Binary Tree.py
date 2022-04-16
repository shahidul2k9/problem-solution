# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        s = 0
        stack = []
        sr = root
        while stack or sr:
            while sr:
                stack.append(sr)
                sr = sr.left
            sr = stack.pop()
            s += sr.val
            sr = sr.right

        ans = 0

        def dfs(sr):
            nonlocal ans
            if not sr:
                return 0
            else:
                v = sr.val
                left = dfs(sr.left)
                right = dfs(sr.right)
                ans = max(ans, left * (s - left))
                ans = max(ans, right * (s - right))
                return left + right + v

        dfs(root)
        return ans % (10 ** 9 + 7)

