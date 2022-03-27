# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.lca = None
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def find_lca(root, p, q):
            if root == None:
                return False
            left = find_lca(root.left, p, q)
            right = find_lca(root.right, p, q)
            mid = root == p or root == q
            if left + right + mid >= 2:
                self.lca = root
            return left or right or mid
        find_lca(root, p, q)
        return self.lca
