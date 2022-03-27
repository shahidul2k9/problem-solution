from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        def construct(p, s, a, b):
            n = len(p)
            if s >= n or p[s] < a or p[s] > b:
                return (s, None)
            li, ln = construct(p, s + 1, a, p[s])
            ri, rn = construct(p, li, p[s], b)

            return (ri, TreeNode(p[s], ln, rn))

        return construct(preorder, 0, float('-inf'), float('inf'))[1]
