# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:

        def dfs(st, bag, level):
            if st:
                bag[level] = bag.get(level, 0) + st.val
                dfs(st.left, bag, level + 1)
                dfs(st.right, bag, level + 1)

        level_wise_sum = {}
        dfs(root, level_wise_sum, 1)
        optimal_level = 1
        for level in sorted(level_wise_sum.keys()):
            if level_wise_sum[level] > level_wise_sum[optimal_level]:
                optimal_level = level
        return optimal_level
