# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs_prune(st):
            if not st:
                return None
            else:
                st.left = dfs_prune(st.left)
                st.right = dfs_prune(st.right)
                if st.left == None and st.right == None and st.val != 1:
                    return None
                else:
                    return st
        return dfs_prune(root)
