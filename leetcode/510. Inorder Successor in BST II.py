"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""


class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        if node.right:
            down = node.right
            while down.left:
                down = down.left
            return down
        else:
            par = node.parent
            while par and par.left != node:
                node, par = par, par.parent
            return par
