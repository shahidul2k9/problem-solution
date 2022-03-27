import bisect
from random import random
from typing import List


class Solution:

    def __init__(self, w: List[int]):
        for i in range(1, len(w)):
            w[i] += w[i - 1]

    def pickIndex(self) -> int:
        r = random() * self.w[-1]
        return bisect.bisect_left(self.w, r)
