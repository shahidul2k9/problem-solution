from typing import List


class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        def is_possible(rb_len):
            sz = 0
            for r in ribbons:
                sz += r // rb_len
                if sz >= k:
                    return True
            return False

        s = sum(ribbons)
        if s < k:
            return 0
        else:
            low = 1
            high = s
            while low <= high:
                mid = (low + high) // 2
                if not is_possible(mid):
                    high = mid - 1
                else:
                    low = mid + 1
            return low - 1
