# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
from typing import List


class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        encoded_tree = collections.defaultdict(int)
        duplicate_tree = []

        def dfs(rt):
            if not rt:
                return '#'
            else:
                et = str(rt.val) + '$' + dfs(rt.left) + '$' + dfs(rt.right)
                encoded_tree[et] += 1
                if encoded_tree[et] == 2:
                    duplicate_tree.append(rt)
                return et

        dfs(root)
        return duplicate_tree
