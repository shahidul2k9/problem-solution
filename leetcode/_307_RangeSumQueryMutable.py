import math
from typing import List


class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        st = [None] * (1 << (math.ceil(math.log2(self.n)) + 1))
        self.st = st

        def build(a, b, r):
            if a == b:
                st[r] = nums[a - 1]
            else:
                mid = (a + b) // 2
                build(a, mid, 2 * r)
                build(mid + 1, b, 2 * r + 1)
                st[r] = st[2 * r] + st[2 * r + 1]

        build(1, self.n, 1)

    def update(self, index: int, val: int) -> None:
        st = self.st

        def sg_update(a, b, target_index, r):
            if not (target_index < a or target_index > b):
                if a == b:
                    st[r] = val
                else:
                    mid = (a + b) // 2
                    sg_update(a, mid, target_index, 2 * r)
                    sg_update(mid + 1, b, target_index, 2 * r + 1)
                    st[r] = st[2 * r] + st[2 * r + 1]

        sg_update(1, self.n, index + 1, 1)

    def sumRange(self, left: int, right: int) -> int:
        st = self.st

        def sum(a, b, lt, rt, r):
            if b < lt or a > rt:
                return 0
            elif lt <= a and b <= rt:
                return st[r]
            else:
                mid = (a + b) // 2
                return sum(a, mid, lt, rt, r * 2) + sum(mid + 1, b, lt, rt, r * 2 + 1)

        return sum(1, self.n, left + 1, right + 1, 1)

