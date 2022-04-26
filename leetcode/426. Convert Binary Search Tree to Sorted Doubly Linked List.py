"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""


class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        def link_nodes(sb):
            if not sb.left and not sb.right:
                return [sb, sb]
            elif not sb.left:
                s, e = link_nodes(sb.right)
                sb.right, s.left = s, sb
                return [sb, e]
            elif not sb.right:
                s, e = link_nodes(sb.left)
                e.right, sb.left = sb, e
                return [s, sb]
            else:
                s1, e1 = link_nodes(sb.left)
                s2, e2 = link_nodes(sb.right)
                e1.right, sb.right, s2.left, sb.left = sb, s2, sb, e1
                return [s1, e2]

        if not root:
            return None
        else:
            [s, e] = link_nodes(root)
            e.right, s.left = s, e
            return s
