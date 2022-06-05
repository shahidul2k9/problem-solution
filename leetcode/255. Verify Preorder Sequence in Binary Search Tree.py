from typing import List
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        index = 0

        def validate(left, right) -> bool:
            nonlocal index
            if index >= len(preorder):
                return True
            val = preorder[index]

            if left < val < right:
                index += 1
                return validate(left, val) or validate(val, right)
            else:
                return False

        return validate(float('-inf'), float('inf'))
