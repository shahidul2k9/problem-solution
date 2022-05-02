from typing import List


class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        def is_trip_possible(t) -> bool:
            trips = 0
            for tp in time:
                trips += t // tp
            return trips >= totalTrips

        time.sort()
        low = min(time)
        high = totalTrips * min(time)
        last_known_ans = None
        while low <= high:
            mid = (low + high) // 2
            if is_trip_possible(mid):
                last_known_ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return last_known_ans
