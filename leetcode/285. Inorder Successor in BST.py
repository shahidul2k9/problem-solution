from typing import Optional


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        def find_pred(sb, predecessor) -> TreeNode:
            if not sb:
                return None
            elif sb == p:
                return predecessor
            else:
                pd = find_pred(sb.left, sb)
                if pd:
                    return pd
                else:
                    return find_pred(sb.right, predecessor)

        if p.right:
            sb = p.right
            while sb.left:
                sb = sb.left
            return sb
        else:
            return find_pred(root, None)