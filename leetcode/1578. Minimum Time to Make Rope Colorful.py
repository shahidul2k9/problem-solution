from typing import List


class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        stack = []
        removal_time = 0
        last_i = 0
        max_t = sum_t = neededTime[0]
        for i in range(1, len(colors)):
            t = neededTime[i]
            if colors[i - 1] == colors[i]:
                max_t = max(max_t, t)
                sum_t += t
            else:
                if i - last_i > 1:
                    removal_time += (sum_t - max_t)
                last_i = i
                max_t = sum_t = t
        if len(colors) - last_i > 1:
            removal_time += (sum_t - max_t)

        return removal_time