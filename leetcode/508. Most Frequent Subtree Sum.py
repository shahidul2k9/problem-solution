# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        frequency = collections.defaultdict(int)

        def sum(sub_root) -> int:
            if sub_root:
                val = total = sub_root.val
                left_sum = sum(sub_root.left)
                right_sum = sum(sub_root.right)
                if sub_root.left:
                    total += left_sum
                if sub_root.right:
                    total += right_sum
                frequency[total] += 1
                return total
            else:
                return 0

        sum(root)
        max_frequency = max(frequency.values())
        frequent_sums = []
        for key, fc in frequency.items():
            if fc == max_frequency:
                frequent_sums.append(key)
        return frequent_sums
