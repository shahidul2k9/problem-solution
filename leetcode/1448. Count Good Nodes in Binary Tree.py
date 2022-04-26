# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        good_nodes = 0

        def count_good_nodes(sb, max_val_seen) -> int:
            nonlocal good_nodes
            if sb:
                if max_val_seen <= sb.val:
                    good_nodes += 1
                count_good_nodes(sb.left, max(max_val_seen, sb.val))
                count_good_nodes(sb.right, max(max_val_seen, sb.val))

        count_good_nodes(root, float('-inf'))
        return good_nodes
