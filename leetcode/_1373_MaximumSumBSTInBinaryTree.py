from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.maxVal = 0

    def maxSumBST(self, root: Optional[TreeNode]) -> int:

        def findMax(root: TreeNode):
            if root is None:
                return (True, 0, float('-inf'), float('inf'))  # isBst[0], sum[1], leftMax[2],rightMin[3]
            else:

                lt = findMax(root.left)
                rt = findMax(root.right)
                if lt[0] and rt[0] and lt[2] < root.val < rt[3]:
                    curMax = root.val + lt[1] + rt[1]
                    self.maxVal = max(curMax, self.maxVal)
                    return (True, curMax, max(root.val, rt[2]), min(root.val, lt[3]))
                else:
                    return (False, 0, 0, 0)
        findMax(root)
        return self.maxVal
