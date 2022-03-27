from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        w = [0] * n
        s = []
        for i, v in enumerate(temperatures):
            while s and temperatures[s[-1]] < v:
                pi = s.pop()
                w[pi] = i - pi
            s.append(i)
        return w
