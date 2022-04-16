# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List


class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        def collect_leaves(nd, leaves):
            if nd:
                if not nd.left and not nd.right:
                    leaves.append(nd.val)
                else:
                    collect_leaves(nd.left, leaves)
                    collect_leaves(nd.right, leaves)

        edge_list = [root.val]
        nd = root.left
        while nd and (nd.left or nd.right):
            edge_list.append(nd.val)
            nd = nd.left if nd.left else nd.right

        if root.left or root.right:
            collect_leaves(root, edge_list)

        nd = root.right
        re = []
        while nd and (nd.left or nd.right):
            re.append(nd.val)
            nd = nd.right if nd.right else nd.left
        edge_list.extend(re[::-1])
        return edge_list
