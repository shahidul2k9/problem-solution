from heapq import heappop, heappush
from typing import List


class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        stations.sort(key=lambda x: x[0])
        max_fuel_heap = []
        tank = startFuel
        refuel_count = 0
        for position, fuel in stations:
            while tank < target and tank < position and max_fuel_heap:
                tank = tank - heappop(max_fuel_heap)
                refuel_count += 1

            if tank >= target:
                return refuel_count
            elif tank < position:
                return -1
            else:
                heappush(max_fuel_heap, -fuel)
        while tank < target and max_fuel_heap:
            tank = tank - heappop(max_fuel_heap)
            refuel_count += 1
        return -1 if tank < target else refuel_count