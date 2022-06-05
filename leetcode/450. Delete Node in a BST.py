from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        def find_successor(node: TreeNode) -> TreeNode:
            while node.left:
                node = node.left
            return node

        def find_predecessor(node: TreeNode) -> TreeNode:
            while node.right:
                node = node.right
            return node

        def delete_recursively(sb: TreeNode, val: int) -> TreeNode:
            if sb:
                if val > sb.val:
                    sb.right = delete_recursively(sb.right, val)
                elif val < sb.val:
                    sb.left = delete_recursively(sb.left, val)
                else:
                    if not (sb.left or sb.right):
                        sb = None
                    elif sb.right:
                        successor = find_successor(sb.right)
                        sb.val = successor.val
                        sb.right = delete_recursively(sb.right, successor.val)
                    else:
                        predecessor = find_predecessor(sb.left)
                        sb.val = predecessor.val
                        sb.left = delete_recursively(sb.left, predecessor.val)
            return sb

        return delete_recursively(root, key)
