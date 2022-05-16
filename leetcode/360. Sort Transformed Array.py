from typing import List


class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        def f(x) -> int:
            return a * x ** 2 + b * x + c

        fx = []
        for x in nums:
            fx.append(f(x))
        fx.sort()
        return fx
