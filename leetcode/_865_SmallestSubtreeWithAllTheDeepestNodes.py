# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:

        def find_depth(sub_root):
            if not sub_root:
                return 0
            else:
                return 1 + max(find_depth(sub_root.left), find_depth(sub_root.right))

        def find_deepest_node(sub_root):

            left_subtree_depth = find_depth(sub_root.left)
            right_subtree_depth = find_depth(sub_root.right)
            if left_subtree_depth > right_subtree_depth:
                return find_deepest_node(sub_root.left)
            elif right_subtree_depth > left_subtree_depth:
                return find_deepest_node(sub_root.right)
            else:
                return sub_root

        return find_deepest_node(root)
