from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        def find_max_depth(sub_root) -> int:
            if sub_root:
                return 1 + max(find_max_depth(sub_root.left), find_max_depth(sub_root.right))
            else:
                return 0

        max_depth = find_max_depth(root)

        def sum_deepest_leaves(sub_root, depth) -> int:
            nonlocal max_depth
            if sub_root:
                if depth == max_depth:
                    return sub_root.val
                else:
                    return sum_deepest_leaves(sub_root.left, depth + 1) + sum_deepest_leaves(sub_root.right, depth + 1)
            else:
                return 0

        return sum_deepest_leaves(root, 1)

