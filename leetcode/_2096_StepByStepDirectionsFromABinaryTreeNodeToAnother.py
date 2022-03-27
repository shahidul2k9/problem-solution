# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:

        def dfsFindPath(root, target, path, lr):

            path.append((root.val if root else None, lr))
            if not root:
                return False

            if root.val == target:
                return True
            if root.left:
                if dfsFindPath(root.left, target, path, 'L'):
                    return True
                else:
                    path.pop()
                    return False

            elif root.right:
                if dfsFindPath(root.right, target, path, 'R'):
                    return True
                else:
                    path.pop()
                    return False

        start_path = []
        dest_path = []
        dfsFindPath(root, startValue, start_path, 'o')
        dfsFindPath(root, destValue, dest_path, 'o')
        p = 0
        while p < min(len(start_path), len(dest_path)) and start_path[p][0] == dest_path[p][0]:
            p += 1
        path = []
        for i in range(len(start_path) - 1, p - 1, -1):
            path.append('U')
        for i in range(p, len(dest_path), 1):
            path.append(dest_path[i][1])
        return path
