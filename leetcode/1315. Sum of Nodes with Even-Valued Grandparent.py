# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        s = 0

        def sum_grand_child(sb, parent, grand_parent):
            nonlocal s
            if sb:
                if grand_parent and grand_parent.val % 2 == 0:
                    s += sb.val
                sum_grand_child(sb.left, sb, parent)
                sum_grand_child(sb.right, sb, parent)

        sum_grand_child(root, None, None)
        return s

