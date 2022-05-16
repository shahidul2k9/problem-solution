"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
from typing import List


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        n = len(grid)
        pfs = [[0] * (n + 1) for _ in range(n + 1)]

        for r in range(1, n + 1):
            for c in range(1, n + 1):
                pfs[r][c] = pfs[r - 1][c] + pfs[r][c - 1] - pfs[r - 1][c - 1] + grid[r - 1][c - 1]

        def construct_quad_tree(r1, c1, d):
            r2, c2 = r1 + d - 1, c1 + d - 1
            s = pfs[r2][c2] - pfs[r1 - 1][c2] - pfs[r2][c1 - 1] + pfs[r1 - 1][c1 - 1]
            if s == 0 or s == d * d:
                return Node(s > 0, True, None, None, None, None)
            else:
                qd = d // 2
                top_left = construct_quad_tree(r1, c1, qd)
                top_right = construct_quad_tree(r1, c1 + qd, qd)
                bottom_left = construct_quad_tree(r1 + qd, c1, qd)
                bottom_right = construct_quad_tree(r1 + qd, c1 + qd, qd)
                val = top_left.val > 0 or top_right.val > 0 or bottom_left.val > 0 or bottom_right.val > 0
                return Node(val, False, top_left, top_right, bottom_left, bottom_right)

        return construct_quad_tree(1, 1, n)



