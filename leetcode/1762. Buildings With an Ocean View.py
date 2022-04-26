from typing import List


class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        max_right = 0
        ocean_view_buildings = []
        for ri in range(len(heights) - 1, -1, -1):
            if heights[ri] > max_right:
                ocean_view_buildings.append(ri)
            max_right = max(max_right, heights[ri])
        return ocean_view_buildings[::-1]

