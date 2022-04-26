import collections


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List


class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        vod = collections.defaultdict(list)
        q = collections.deque()
        if root:
            q.append([root, 0])
        while q:
            sb, col = q.popleft()
            vod[col].append(sb.val)
            if sb.left:
                q.append([sb.left, col - 1])
            if sb.right:
                q.append([sb.right, col + 1])
        return list(map(lambda k: vod[k], sorted(vod.keys())))
