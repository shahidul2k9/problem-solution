"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""


class Solution:
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """
        d = 0

        def depth_list(sb, depth):
            if len(sb.children) == 0:
                return depth
            else:
                nonlocal d
                a = b = depth
                for c in sb.children:
                    ch1 = depth_list(c, depth + 1)
                    if ch1 >= a:
                        a, b = ch1, a
                    elif ch1 > b:
                        b = ch1
                    d = max(d, a - depth + b - depth)
                return a

        depth_list(root, 0)
        return d
