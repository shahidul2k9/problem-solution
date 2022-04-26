# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def find_min(sb):
            nonlocal ans
            val = sb.val
            left = find_min(sb.left) if sb.left else [val, val]
            right = find_min(sb.right) if sb.right else [val, val]
            min_child_val = min(left[0], right[0])
            max_child_val = max(left[1], right[1])
            ans = max(ans, abs(val - min_child_val), abs(val - max_child_val))
            return [min(min_child_val, val), max(max_child_val, val)]

        find_min(root)
        return ans
