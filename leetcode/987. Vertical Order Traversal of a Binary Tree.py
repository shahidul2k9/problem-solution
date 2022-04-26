# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
from typing import List


class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        vt = []
        q = collections.deque([[root, 0, 0]])
        while q:
            sb, col, row = q.popleft()
            vt.append([col, row, sb.val])
            if sb.left:
                q.append([sb.left, col - 1, row + 1])
            if sb.right:
                q.append([sb.right, col + 1, row + 1])
        vt.sort()
        col_list = []

        cur_col = [vt[0][2]]
        for i in range(1, len(vt)):
            if vt[i - 1][0] == vt[i][0]:
                cur_col.append(vt[i][2])
            else:
                col_list.append(cur_col)
                cur_col = [vt[i][2]]
        col_list.append(cur_col)
        return col_list

