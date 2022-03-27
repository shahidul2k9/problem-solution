from typing import List


class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        wrapper_max = max(milestones)
        total = sum(milestones)
        in_between_scattered = total - wrapper_max
        if in_between_scattered >= wrapper_max:
            return total
        else:
            return 2 * in_between_scattered + 1
