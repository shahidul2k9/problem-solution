# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        width = dict()

        def preorder(cr: TreeNode | None, level: int, idx: int):
            if cr:
                if level not in width:
                    width[level] = [float('inf'), float('-inf')]
                width[level] = [min(idx, width[level][0]), max(idx, width[level][1])]
                preorder(cr.left, level + 1, 2 * idx)
                preorder(cr.right, level + 1, 2 * idx + 1)

        preorder(root, 0, 1)
        return max(map(lambda x: x[1] - x[0] + 1, width.values()))
