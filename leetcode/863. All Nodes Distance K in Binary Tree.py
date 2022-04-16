# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections
from typing import List


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        par = dict()

        def link_parent(cr, p):
            if cr:
                par[cr] = p
                link_parent(cr.left, cr)
                link_parent(cr.right, cr)

        link_parent(root, None)

        ans = []
        q = collections.deque([target])
        seen = {target}
        level = 0
        while q:
            prev_ln = len(q)
            for i in range(prev_ln):
                u = q.popleft()
                if level == k:
                    ans.append(u.val)
                if level < k:
                    for v in [u.left, u.right, par[u]]:
                        if v and v not in seen:
                            seen.add(v)
                            q.append(v)
            level += 1
        return ans



