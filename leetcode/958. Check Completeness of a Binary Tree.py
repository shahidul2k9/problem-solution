# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
from typing import Optional


class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q = collections.deque([[root, 1]])
        idx = 1
        while q:
            sb, p_idx = q.popleft()
            if sb.left:
                if 2 * p_idx != idx + 1:
                    return False
                idx += 1
                q.append([sb.left, idx])
            if sb.right:
                if 2 * p_idx + 1 != idx + 1:
                    return False
                idx += 1
                q.append([sb.right, idx])
        return True
