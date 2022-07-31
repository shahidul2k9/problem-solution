# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from typing import List


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        path_list = []

        def find_paths(sub_root: 'TreeNode', path: List[int]):
            if sub_root:
                path.append(sub_root)
                if sub_root == p or sub_root == q:
                    path_list.append(path[:])

                find_paths(sub_root.left, path)
                find_paths(sub_root.right, path)
                path.pop()

        find_paths(root, [])
        if len(path_list) < 2:
            return None
        else:
            path1 = path_list[0]
            path2 = path_list[1]
            index = 0
            while index < min(len(path1), len(path2)) and path1[index] == path2[index]:
                index += 1
            return path1[index - 1]


