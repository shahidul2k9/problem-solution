from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        fleet_count = 0
        ps = [[position[i], speed[i]] for i in range(len(position))]
        ps.sort(reverse=True)

        clock = float('-inf')
        for p, s in ps:
            d = target - p
            if d / s > clock:
                clock = d / s
                fleet_count += 1
        return fleet_count
