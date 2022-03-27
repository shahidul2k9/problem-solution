# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List


class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        max_val_map = dict()

        def dfs(st, depth):
            if st:
                max_val_map.setdefault(depth, st.val)
                max_val_map[depth] = max(st.val, max_val_map[depth])
                dfs(st.left, depth + 1)
                dfs(st.right, depth + 1)

        dfs(root, 0)
        return [max_val_map[k] for k in sorted(max_val_map.keys())]
