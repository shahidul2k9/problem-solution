# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List


class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        deletable_set = set(to_delete)
        sub_tree_collection = []

        def dfs(r, is_collected):
            if r:
                if r.val not in deletable_set and not is_collected:
                    sub_tree_collection.append(r)
                    is_collected = True
                if r.val in deletable_set:
                    is_collected = False

                if dfs(r.left, is_collected):
                    r.left = None
                if dfs(r.right, is_collected):
                    r.right = None
                return r.val in deletable_set
            else:
                return False
        dfs(root,False)

        return sub_tree_collection
