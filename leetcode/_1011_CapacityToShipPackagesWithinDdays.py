from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def is_deliverable(capacity):
            chunk_size = 0
            days_required = 0
            for w in weights:
                if chunk_size + w > capacity:
                    chunk_size = 0
                    days_required += 1
                    if days_required > days:
                        return False
                chunk_size += w
            return days_required + 1 <= days if chunk_size > 0 else days_required <= days

        hi = sum(weights)
        lo = max(weights)
        possible_capacity = 0
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if is_deliverable(mid):
                possible_capacity = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return possible_capacity
