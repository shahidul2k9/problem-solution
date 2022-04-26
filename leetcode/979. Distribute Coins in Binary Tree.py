# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional


class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        total_move = 0

        def distribute_coin(sb):
            nonlocal total_move
            if not sb:
                return 0
            else:
                left = distribute_coin(sb.left)
                right = distribute_coin(sb.right)
                total_move += abs(left) + abs(right)
                return sb.val + left + right - 1

        distribute_coin(root)
        return total_move
