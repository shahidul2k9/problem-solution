"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):

"""
from typing import List


class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        domains = []
        for x in range(1, 1001):
            for y in range(1, 1001):
                fz = customfunction.f(x, y)
                if fz == z:
                    domains.append([x, y])
                elif fz > z:
                    break
        return domains