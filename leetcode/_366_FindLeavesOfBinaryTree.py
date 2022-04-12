# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
from typing import List


class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        leaves = collections.defaultdict(list)

        def dfs(sb_root):
            if not sb_root:
                return -1
            else:
                d = max(dfs(sb_root.left), dfs(sb_root.right)) + 1
                leaves[d].append(sb_root.val)
                return d

        dfs(root)
        return [leaves[l] for l in sorted(leaves.keys())]
